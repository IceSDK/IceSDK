#include "pch.h"

#include "SpriteBatch.h"

#include "Utils/Logger.h"

#include "GameBase.h"

using namespace IceSDK::Graphics;

static std::array<glm::vec2, QUAD_COUNT> _def_tex_coords = {
    glm::vec2(0.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, 0.0f),
    glm::vec2(0.0f, 0.0f)
};

SpriteBatch::SpriteBatch()
{
    this->vertex_buffer_base = new VertexInfo[this->max_vertices];
    uint32_t* quads = new uint32_t[this->max_indices];
    uint32_t offset = 0;

    for (uint32_t i = 0; i < this->max_indices; i += 6)
    {
        quads[i + 0] = offset + 0;
        quads[i + 1] = offset + 1;
        quads[i + 2] = offset + 2;

        quads[i + 3] = offset + 2;
        quads[i + 4] = offset + 3;
        quads[i + 5] = offset + 0;

        offset += 4;
    }

    this->index_handle = bgfx::createIndexBuffer(
        bgfx::copy(quads, max_indices * sizeof(uint32_t)));
    delete[] quads;

    this->vertex_layout.begin()
        .add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
        .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
        .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Float, true)
        .end();

    this->texture =
        bgfx::createUniform("s_texColour", bgfx::UniformType::Sampler);

    this->vertex_positions[0] = { -0.5f, -0.5f, 0.0f, 1.0f };
    this->vertex_positions[1] = { 0.5f, -0.5f, 0.0f, 1.0f };
    this->vertex_positions[2] = { 0.5f, 0.5f, 0.0f, 1.0f };
    this->vertex_positions[3] = { -0.5f, 0.5f, 0.0f, 1.0f };
}

void SpriteBatch::NewFrame()
{
    this->indexes = 0;
    this->vertex_buffer_ptr = this->vertex_buffer_base;
    this->texture_index = 0;
}

void SpriteBatch::EndFrame()
{
    uint32_t data_size = (uint32_t)((uint8_t*) this->vertex_buffer_ptr
                                    - (uint8_t*) this->vertex_buffer_base);

    bgfx::TransientVertexBuffer vb;
    bgfx::allocTransientVertexBuffer(&vb, data_size, this->vertex_layout);
    vb.data = (uint8_t*) this->vertex_buffer_base;

    bgfx::setVertexBuffer(0, &vb);

    Flush();
}

void SpriteBatch::Flush()
{
    if (!this->indexes) return;

    for (uint32_t i = 0; i < this->texture_index; i++)
        bgfx::setTexture(0, this->texture, this->texture_slots[i]->GetHandle());

    uint32_t count = this->indexes ? this->indexes : this->max_indices;
    bgfx::setIndexBuffer(this->index_handle, 0, count);

    bgfx::setState(0 | BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A
                   | BGFX_STATE_BLEND_ALPHA);

    auto shader = GetGameBase()->GetShaderManager()->LoadProgram("Sprite");
    bgfx::submit(0, shader);
}

void SpriteBatch::FlushReset()
{
    EndFrame();

    this->indexes = 0;
    this->vertex_buffer_ptr = this->vertex_buffer_base;
    this->texture_index = 0;
}

void SpriteBatch::SubmitTexturedQuad(Memory::Ptr<Texture2D> texture,
                                     const glm::vec2& position,
                                     const glm::vec2& size,
                                     const glm::vec4& color)
{
    CheckIndexes();
    glm::mat4 transform =
        glm::translate(glm::mat4(1.0f), { position.x, position.y, 1 })
        * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });

    bgfx::setTransform(glm::value_ptr(transform));

    DrawIndexed(transform, this->vertex_positions, _def_tex_coords, color,
                SetTexture(texture));
}

void SpriteBatch::CheckIndexes()
{
    if (this->indexes >= SpriteBatch::max_indices) FlushReset();
}

void SpriteBatch::DrawIndexed(glm::mat4 transform,
                              glm::vec4 vertex_pos[QUAD_COUNT],
                              std::array<glm::vec2, QUAD_COUNT> uvs,
                              glm::vec4 color, float texture_id,
                              uint32_t index_count)
{
    for (size_t i = 0; i < QUAD_COUNT; i++)
    {
        this->vertex_buffer_ptr->pos = vertex_pos[i];
        this->vertex_buffer_ptr->color = color;
        this->vertex_buffer_ptr->texture_pos = uvs[i];
        /*this->vertex_buffer_ptr->texture_id = texture_id;
        this->vertex_buffer_ptr->tiling = 1.f;*/
        this->vertex_buffer_ptr++;
    }
    this->indexes += index_count;
}

float SpriteBatch::SetTexture(Memory::Ptr<Texture2D> texture)
{
    float textureIndex = 0.0f;
    for (uint32_t i = 0; i < this->texture_index; i++)
    {
        if (*this->texture_slots[i] == *texture)
        {
            textureIndex = (float) i;
            break;
        }
    }

    if (textureIndex == 0.0f)
    {
        if (this->texture_index >= SpriteBatch::max_texture_slots) FlushReset();

        textureIndex = (float) this->texture_index;
        this->texture_slots[this->texture_index] = texture;
        this->texture_index++;
    }

    return textureIndex;
}