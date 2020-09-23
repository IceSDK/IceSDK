#pragma once

#include "FontAtlas.h"
#include "Graphics/Texture2D.h"

namespace IceSDK::Graphics
{
    class FontFace
    {
    public:
        static Memory::Ptr<FontFace> FromMemory(const std::vector<uint8_t> &pData, size_t pFontSize);
        static Memory::Ptr<FontFace> FromFile(const std::string &pPath, size_t pFontSize);

        static void Init();

        // NOTE: This will clear the whole cache
        // and all it's font atlasses! it'll slow down
        // on the first render
        void SetSize(size_t size);
        size_t GetSize();

        // Load a single character to a font atlas
        void LoadGlyph(uint32_t glyph);

        float GetKerningOffset(uint32_t pGlyph, uint32_t pPreviousGlyph);

        Glyph &GetGlyph(uint32_t glyph);

        Memory::Ptr<Texture2D> GetAtlas(size_t index);

    private:
        FT_Face _face;
        size_t _size;

        std::vector<FontAtlas> _font_atlases{};
    };
} // namespace IceSDK::Graphics
