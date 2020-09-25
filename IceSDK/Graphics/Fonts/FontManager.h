#pragma once

#include "Graphics/Fonts/FontFace.h"

#define INVALID_FONT_FACE_HANDLE -1

namespace IceSDK::Graphics
{
    typedef int32_t FontFaceHandle;

    class FontManager
    {
    public:
        std::tuple<Glyph, Memory::Ptr<FontFace>> GetGlyph(FontFaceHandle pFont, uint32_t pGlyph, size_t pSize);

        FontFaceHandle LoadFont(std::vector<uint8_t> pBuffer);
        FontFaceHandle LoadFont(const std::string &pPath);

    private:
        FontFaceHandle _face_index;
        std::unordered_map<FontFaceHandle, std::vector<uint8_t>> _faces_buffer;
        std::unordered_map<FontFaceHandle, std::vector<Memory::Ptr<FontFace>>> _faces;
    };
} // namespace IceSDK::Graphics
