#pragma once

#include "Graphics/Fonts/FontFace.h"

#define INVALID_FONT_FACE_HANDLE (::IceSDK::Graphics::FontFaceHandle)0

namespace IceSDK::Graphics
{
    typedef int32_t FontFaceHandle;

    class FontManager
    {
    public:
        Glyph GetGlyph(uint32_t glyph);

    private:
    };
} // namespace IceSDK::Graphics
