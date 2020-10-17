#pragma once

#include "Utils/Memory.h"

#include "Graphics/Texture2D.h"

#include <bgfx/bgfx.h>
#include <glm/glm.hpp>

#include <array>

#define QUAD_COUNT 4

namespace IceSDK
{
    namespace Graphics
    {
        static const uint32_t _maxQuads = 20000;
        static const uint32_t _maxVertices = _maxQuads * 4;
        static const uint32_t _maxIndices = _maxQuads * 6;
        static const uint32_t _maxTextureSlots = 16;

        struct VertexInfo
        {
            glm::vec2 pos;
            glm::vec2 texture_pos;
            glm::vec4 color;
            glm::vec2 batch_info;
        };

        class SpriteBatch
        {
        public:
            explicit SpriteBatch();
            ~SpriteBatch();

            void NewFrame();
            void EndFrame();
            void Flush();
            void FlushReset();

            void SubmitTexturedQuad(Memory::Ptr<Texture2D> pTexture,
                                    const glm::vec2& pPosition,
                                    const glm::vec2& pSize,
                                    const glm::vec4& pColour);

            void SubmitTiledSprite(Memory::Ptr<Texture2D> pTexture,
                                   const glm::vec2& pPosition,
                                   const glm::vec2& pSize,
                                   const glm::vec4& pTileInfo,
                                   const glm::vec4& pColour);

            void CheckIndexes();
            void DrawIndexed(glm::mat4 transform,
                             glm::vec4 vertex_pos[QUAD_COUNT],
                             std::array<glm::vec2, QUAD_COUNT> uvs,
                             const glm::vec4& pColour, float texture_id = 0.f,
                             uint32_t index_count = 6);

            float SetTexture(Memory::Ptr<Texture2D> pTexture);
            
            std::array<glm::vec2, QUAD_COUNT> MakeTiled(
                Memory::Ptr<Texture2D> pTexture, const glm::vec4& pTileInfo);

        private:
            /*
                Sprite batch,
                some raw pointers don't require smart pointers, let
                them stay raw. we already delete them at the end so
                don't bother adding any smart pointer for quads or
                vertex_XX
            */
            uint32_t _indexes;
            uint32_t _textureIndex;

            glm::vec4 _vertexPositions[4];
            std::array<Memory::Ptr<Texture2D>, _maxTextureSlots> _textureSlots;
            //                                 ^^^^^^^^^^^^^^^^^ texture count -
            //                                 we can get it with bgfx::caps

            VertexInfo* _vertexBuffer;
            VertexInfo* _vertexBufferPtr;

            bgfx::VertexLayout _vertexLayout;
            bgfx::IndexBufferHandle _indexHandle;

            std::array<bgfx::UniformHandle, _maxTextureSlots>
                _textureUniforms;  // size of that member must be same as
                                   // _textureSlots
        };
    }  // namespace Graphics
}  // namespace IceSDK
