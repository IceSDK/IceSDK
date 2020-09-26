#pragma once

#include "Graphics/Texture2D.h"

#include <glm/vec2.hpp>

namespace IceSDK::Graphics::Components
{
    struct SpriteComponent
    {
        glm::vec2 size;

        Memory::Ptr<Graphics::Texture2D> texture;
    };
}  // namespace IceSDK::Graphics::Components
