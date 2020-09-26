#pragma once

#include <bgfx/bgfx.h>

namespace IceSDK::Graphics::Components
{
    struct MeshComponent
    {
        bgfx::VertexBufferHandle vertex_buffer;
        bgfx::IndexBufferHandle index_buffer;
    };
}  // namespace IceSDK::Graphics::Components
