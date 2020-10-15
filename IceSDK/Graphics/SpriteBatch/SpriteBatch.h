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

        void SubmitTexturedQuad(Memory::Ptr<Texture2D> pTexture, const glm::vec2 &position, const glm::vec2 &size, const glm::vec4 &color);

        void CheckIndexes();
        void DrawIndexed(glm::mat4 transform, glm::vec4 vertex_pos[QUAD_COUNT],
                         std::array<glm::vec2, QUAD_COUNT> uvs, glm::vec4 color,
                         float texture_id = 0.f, uint32_t index_count = 6);

        float SetTexture(Memory::Ptr<Texture2D> pTexture);

    private:
        static const uint32_t _maxQuads = 20000;
        static const uint32_t _maxVertices = _maxQuads * 4;
        static const uint32_t _maxIndices = _maxQuads * 6;
        static const uint32_t _maxTextureSlots = 16;

        uint32_t _indexes = 0;
        uint32_t _textureIndex = 0;

        glm::vec4 _vertexPositions[4];
        std::array<Memory::Ptr<Texture2D>, _maxTextureSlots> _textureSlots;
        //                                 ^^^^^^^^^^^^^^^^^ texture count - we can get it
        //                                 with bgfx::caps

        VertexInfo* _vertexBuffer = nullptr;
        VertexInfo* _vertexBufferPtr = nullptr;

        bgfx::VertexLayout _vertexLayout;
        bgfx::IndexBufferHandle _indexHandle;

        bgfx::UniformHandle _textureUniform;
    };
}  // namespace IceSDK::Graphics
