#pragma once

#include "Graphics/Texture2D.h"

#include <bgfx/bgfx.h>
#include <glm/glm.hpp>

#include <array>

#define QUAD_COUNT 4

namespace IceSDK::Graphics
{
    struct VertexInfo
    {
        glm::vec2 pos;
        glm::vec2 texture_pos;
        glm::vec4 color;
    };

    class SpriteBatch
    {
    public:
        SpriteBatch();

        void NewFrame();
        void EndFrame();
        void Flush();
        void FlushReset();

        void SubmitTexturedQuad(Memory::Ptr<Texture2D> texture, const glm::vec2 &position, const glm::vec2 &size, const glm::vec4 &color);

        void CheckIndexes();
        void DrawIndexed(glm::mat4 transform, glm::vec4 vertex_pos[QUAD_COUNT],
                         std::array<glm::vec2, QUAD_COUNT> uvs, glm::vec4 color,
                         float texture_id = 0.f, uint32_t index_count = 6);

        float SetTexture(Memory::Ptr<Texture2D> texture);

    private:
        static const uint32_t max_quads = 20000;
        static const uint32_t max_vertices = max_quads * 4;
        static const uint32_t max_indices = max_quads * 6;
        static const uint32_t max_texture_slots = 16;

        uint32_t indexes = 0;
        uint32_t texture_index = 0;

        glm::vec4 vertex_positions[4];
        std::array<Memory::Ptr<Texture2D>, max_texture_slots> texture_slots;
        //                                 ^^^^^^^^^^^^^^^^^ texture count - we can get it
        //                                 with bgfx::caps

        VertexInfo* vertex_buffer_base = nullptr;
        VertexInfo* vertex_buffer_ptr = nullptr;

        bgfx::VertexLayout vertex_layout;
        bgfx::IndexBufferHandle index_handle;

        bgfx::UniformHandle texture;
    };
}  // namespace IceSDK::Graphics
