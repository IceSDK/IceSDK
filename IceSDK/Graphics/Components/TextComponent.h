#pragma once

#include <string>

#include "Graphics/Fonts/FontManager.h"

namespace IceSDK::Graphics::Components
{
    struct TextComponent
    {
        std::string text;
        uint64_t _old_text;

        size_t font_size;

        FontFaceHandle font_face_handle;
    };
} // namespace IceSDK::Graphics::Components