#pragma once

#include "Graphics/Texture2D.h"

#include <glm/vec2.hpp>

#include <hb-ft.h>
#include <hb.hh>

#include <vector>

#undef getenv  // Harfbuzz sets this but it's incompatible with spdlog

namespace IceSDK::Graphics
{
    struct Glyph
    {
        glm::vec2 Size;  // Bottom && Right
        float BearingBase;
        float GlyphTop;

        std::vector<uint8_t> PixelData;
    };

    class FontFace
    {
    public:
        ~FontFace()
        {
            hb_buffer_destroy(this->_buffer);
            hb_font_destroy(this->_font);
        }

        static Memory::Ptr<FontFace> FromMemory(
            const std::vector<uint8_t>& pData, size_t pFontSize);
        static Memory::Ptr<FontFace> FromFile(const std::string& pPath,
                                              size_t pFontSize);

        static void Init();

        // NOTE: This will clear the whole cache
        // and all it's font atlasses! it'll slow down
        // on the first render
        void SetSize(size_t pSize);
        size_t GetSize();

        // Load a single character to a font atlas
        Glyph& GetGlyph(uint32_t pGlyph);

        hb_buffer_t* _hb_buffer() { return _buffer; }

        hb_font_t* _hb_font() { return _font; }

    private:
        hb_buffer_t* _buffer;
        hb_font_t* _font;
        FT_Face _face;
        size_t _size;

        std::unordered_map<uint32_t, Glyph> _glyphCache;
    };
}  // namespace IceSDK::Graphics
