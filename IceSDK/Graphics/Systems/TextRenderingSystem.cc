#include "pch.h"

#include "GameBase.h"

#include "Graphics/Fonts/FontManager.h"
#include "Graphics/Components/TextComponent.h"
#include "Graphics/Components/SpriteComponent.h"
#include "Graphics/Systems/TextRenderingSystem.h"

#include "ECS/Entity.h"

#include "Utils/Math.h"
#include "Utils/String.h"
#include "Utils/Instrumentor.h"
#include "Utils/Logger.h"

#include "hb-icu.h"

using namespace IceSDK;
using namespace IceSDK::Systems;
using namespace IceSDK::Graphics;
using namespace IceSDK::Graphics::Components;

// https://github.com/tangrams/harfbuzz-example/blob/master/src/hbshaper.h
// under MIT license!
namespace HBFeature
{
    const hb_tag_t KernTag = HB_TAG('k', 'e', 'r', 'n'); // kerning operations
    const hb_tag_t LigaTag = HB_TAG('l', 'i', 'g', 'a'); // standard ligature substitution
    const hb_tag_t CligTag = HB_TAG('c', 'l', 'i', 'g'); // contextual ligature substitution

    static hb_feature_t LigatureOff = {LigaTag, 0, 0, std::numeric_limits<unsigned int>::max()};
    static hb_feature_t LigatureOn = {LigaTag, 1, 0, std::numeric_limits<unsigned int>::max()};
    static hb_feature_t KerningOff = {KernTag, 0, 0, std::numeric_limits<unsigned int>::max()};
    static hb_feature_t KerningOn = {KernTag, 1, 0, std::numeric_limits<unsigned int>::max()};
    static hb_feature_t CligOff = {CligTag, 0, 0, std::numeric_limits<unsigned int>::max()};
    static hb_feature_t CligOn = {CligTag, 1, 0, std::numeric_limits<unsigned int>::max()};
} // namespace HBFeature

void TextRenderingSystem::Tick(float pDelta)
{
    ICESDK_PROFILE_FUNCTION();
}

void TextRenderingSystem::Draw(float pDelta)
{
    ICESDK_PROFILE_FUNCTION();
    const auto registry = this->_registry.lock();
    if (registry == nullptr)
        return;

    auto textGroup = registry->view<TextComponent>();
    for (auto rawTextEntity : textGroup)
    {
        auto textEntity = Entity(this->_registry, rawTextEntity);

        auto &text = textEntity.GetComponent<TextComponent>();
        auto &sprite = textEntity.GetComponent<SpriteComponent>();

        // Re-render text if it has changed
        if (String::CalculateHash(text.text) + text.font_size != text._old_text)
        {
            auto fontManager = GetGameBase()->GetFontManager();

            // HarfBuzz
            auto [glyph, atlas, fontFace] = fontManager->GetGlyph(text.font_face_handle, text.text[0], text.font_size);

            auto buffer = fontFace->_hb_buffer();
            auto font = fontFace->_hb_font();

            hb_buffer_reset(buffer);

            hb_unicode_funcs_t *icufunctions;
            icufunctions = hb_icu_get_unicode_funcs();
            hb_buffer_set_unicode_funcs(buffer, icufunctions);

            hb_buffer_add_utf8(buffer, text.text.c_str(), text.text.length(), 0, text.text.length());
            hb_buffer_guess_segment_properties(buffer);

            std::vector<hb_feature_t> features;
            features.push_back(HBFeature::KerningOn);
            features.push_back(HBFeature::LigatureOn);
            features.push_back(HBFeature::CligOn);

            hb_shape(font, buffer, &features[0], features.size());

            unsigned int glyphCount;
            hb_glyph_info_t *glyphInfos = hb_buffer_get_glyph_infos(buffer, &glyphCount);
            hb_glyph_position_t *glyphPositions = hb_buffer_get_glyph_positions(buffer, &glyphCount);

            glm::vec2 resolution{};
            float baseLine = 0;
            for (size_t i = 0; i < glyphCount; i++)
            {
                auto glyphInfo = glyphInfos[i];
                auto glyphPos = glyphPositions[i];

                auto xAdvance = glyphPos.x_advance / 64;
                auto yAdvance = glyphPos.y_advance / 64;

                auto [glyph, atlas, fontFace] = fontManager->GetGlyph(text.font_face_handle, glyphInfo.codepoint, text.font_size);

                baseLine = Math::Max(baseLine, glyph.descent);        // Lowest low
                resolution.y = Math::Max(resolution.y, glyph.ascent); // Highest Height

                baseLine = Math::Max(baseLine, glyph.descent);

                uint32_t lastChar = 0;
                if (lastChar >= 1)
                    lastChar = glyphInfos[i - 1].codepoint;
                if ((xAdvance) < (glyph.Size.x))
                    resolution.x += (glyph.Size.x);
                else
                    resolution.x += (xAdvance);
            }

            // Create a Text Sprite
            sprite.size = resolution;
            sprite.texture = Texture2D::Create("Text: " + text.text, resolution.x, resolution.y, bgfx::TextureFormat::RGBA8);

            int xPen = 0;
            int yPen = 0;

            // Draw glyphs
            for (size_t i = 0; i < glyphCount; i++)
            {
                auto glyphInfo = glyphInfos[i];
                auto glyphPos = glyphPositions[i];

                auto xAdvance = glyphPos.x_advance / 64;
                auto yAdvance = glyphPos.y_advance / 64;

                auto xOffset = glyphPos.x_offset / 64;
                auto yOffset = glyphPos.y_offset / 64;

                auto [glyph, atlas, fontFace] = fontManager->GetGlyph(text.font_face_handle, glyphInfo.codepoint, text.font_size);

                yPen = sprite.size.y - glyph.ascent - baseLine;
                // TODO: GPU acceleration using an shader and it's font atlas...
                {
                    const bgfx::Memory *memory = bgfx::alloc(glyph.PixelData.size() * 4);
                    bx::memSet(memory->data, 0, memory->size);
                    for (size_t i = 0; i < glyph.PixelData.size(); i++)
                    {
                        auto pixel = glyph.PixelData.at(i);

                        uint8_t r = (pixel.a * 0xFF), g = (pixel.a * 0xFF), b = (pixel.a * 0xFF), a = (pixel.a * 0xFF);

                        auto pixel_value = ((r & 0xFF) << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | (a & 0xFF);

                        bx::memCopy(&memory->data[i * 4], (void *)&pixel_value, 4);
                    }

                    bgfx::updateTexture2D(sprite.texture->GetHandle(), 0, 0,
                                          floor(xPen + xOffset), floor(yPen + yOffset + baseLine), glyph.Size.x, glyph.Size.y,
                                          memory, glyph.Size.x * 4);
                }
                // TODO end

                xPen += xAdvance;
            }

            text._old_text = String::CalculateHash(text.text) + text.font_size;
        }
    }
}
