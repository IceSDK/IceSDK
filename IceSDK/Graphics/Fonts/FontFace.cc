#include "pch.h"

#include "Graphics/Fonts/FontFace.h"

#include "Utils/FileSystem.h"
#include "Utils/Logger.h"

using namespace IceSDK;
using namespace IceSDK::Graphics;

static FT_Library g_FTLibrary;

Memory::Ptr<FontFace> FontFace::FromMemory(const std::vector<uint8_t> &pData, size_t pFontSize)
{
    Memory::Ptr<FontFace> font = std::make_shared<FontFace>();
    FT_Error err;

    err = FT_New_Memory_Face(g_FTLibrary, pData.data(), pData.size(), 0, &font->_face);
    if (err != FT_Err_Ok)
        ICESDK_CORE_ERROR("Failed to load FontFace! ({:x})", err);

    // Cache most important ascii characters, everything else can be cached at runtime
    const char *ascii = " abcdefghijklmnopqrstuvwxyABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!?.,";

    font->SetSize(pFontSize);

    for (size_t i = 0; i < 65; i++)
    {
        font->LoadGlyph(ascii[i]);
    }

    return font;
}

Memory::Ptr<FontFace> FontFace::FromFile(const std::string &pPath, size_t pFontSize)
{
    if (!FileSystem::Exists(pPath))
        return nullptr;

    return FontFace::FromMemory(FileSystem::ReadBinaryFile(pPath), pFontSize);
}

void FontFace::Init()
{
    FT_Error err;

    err = FT_Init_FreeType(&g_FTLibrary);
    if (err != FT_Err_Ok)
        ICESDK_CORE_CRITICAL("Failed to initialize FreeType! ({:x})", err);
}

void FontFace::SetSize(size_t size)
{
    if (this->_size == size)
        return;
    FT_Error err;

    this->_size = size;
    err = FT_Set_Char_Size(this->_face, 0, this->_size << 6, 96, 96);
    if (err != FT_Err_Ok)
        ICESDK_CORE_ERROR("Failed to change Font size! ({:x})", err);

    this->_font_atlases.clear();
}

size_t FontFace::GetSize()
{
    return this->_size;
}

void FontFace::LoadGlyph(uint32_t glyph)
{
    // We don't want a glyph to be loaded twice!
    for (auto &atlas : this->_font_atlases)
        if (atlas.Glyphs.count(glyph))
            return;

    FT_Error err;
    err = FT_Load_Char(this->_face, glyph, FT_LOAD_RENDER | FT_LOAD_FORCE_AUTOHINT | FT_LOAD_TARGET_LIGHT);
    if (err != FT_Err_Ok)
        ICESDK_CORE_ERROR("Failed to load Font Glyph! ({:x})", err);

    FT_Bitmap *bmp = &this->_face->glyph->bitmap;
    std::vector<glm::vec4> pixel_data;
    pixel_data.reserve(bmp->width * bmp->rows);

    for (int row = 0; row < bmp->rows; ++row)
    {
        for (int col = 0; col < bmp->width; ++col)
        {
            auto pixel = (float)bmp->buffer[row * bmp->pitch + col];
            pixel_data.push_back({1.0, 1.0, 1.0, pixel / 0xFF});
        }
    }

    Glyph _glyph{
        {bmp->width, bmp->rows},
        {this->_face->glyph->bitmap_left, this->_face->glyph->bitmap_top},

        (float)(this->_face->glyph->advance.x >> 6),

        0,

        pixel_data};

    size_t atlasIndex = 0;
    FontAtlas *atlas = nullptr;
    // Find an empty font atlas
    for (auto &_atlas : this->_font_atlases)
    {
        if (_atlas.Fits(_glyph))
        {
            atlas = &_atlas;
            break;
        }

        atlasIndex += 1;
    }

    if (atlas == nullptr)
    {
        this->_font_atlases.emplace_back(); // Push an empty font atlas

        atlas = &this->_font_atlases.at(this->_font_atlases.size() - 1);

        atlas->Atlas = Graphics::Texture2D::Create("FontAtlas", FT_ATLAS_SIZE, FT_ATLAS_SIZE, bgfx::TextureFormat::RGBA8);
    }

    _glyph.Offset = atlas->Pen;
    _glyph.AtlasIndex = atlasIndex;

    atlas->Glyphs.insert({glyph, _glyph});
    atlas->Pen.x += _glyph.Advance;
    if (atlas->Pen.x + _glyph.Size.x >= FT_ATLAS_SIZE)
    {
        atlas->Pen.x = 0;
        atlas->Pen.y += ((this->_face->size->metrics.height >> 6) + 1);
    }

    const bgfx::Memory *memory = bgfx::alloc(_glyph.PixelData.size() * 4);
    bx::memSet(memory->data, 0, memory->size);
    for (size_t i = 0; i < _glyph.PixelData.size(); i++)
    {
        auto pixel = _glyph.PixelData.at(i);

        uint8_t r = (pixel.a * 0xFF), g = (pixel.a * 0xFF), b = (pixel.a * 0xFF), a = (pixel.a * 0xFF);

        auto pixel_value = ((r & 0xFF) << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | (a & 0xFF);

        bx::memCopy(&memory->data[i * 4], (void *)&pixel_value, 4);
    }

    bgfx::updateTexture2D(atlas->Atlas->GetHandle(), 0, 0, atlas->Pen.x, atlas->Pen.y, _glyph.Size.x, _glyph.Size.y, memory, _glyph.Size.x * 4);
}

Glyph &FontFace::GetGlyph(uint32_t glyph)
{
    this->LoadGlyph(glyph); // Make sure glyph is loaded

    for (auto &&atlas : this->_font_atlases)
    {
        if (!atlas.Glyphs.count(glyph))
            break;

        return atlas.Glyphs[glyph];
    }
}

Memory::Ptr<Texture2D> FontFace::GetAtlas(size_t index)
{
    if (this->_font_atlases.size() < index)
        return nullptr;

    return this->_font_atlases[index].Atlas;
}
