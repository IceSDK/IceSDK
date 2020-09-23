#include "pch.h"

#include "GameBase.h"

#include "Graphics/Fonts/FontManager.h"
#include "Graphics/Components/TextComponent.h"
#include "Graphics/Components/SpriteComponent.h"
#include "Graphics/Systems/TextRenderingSystem.h"

#include "ECS/Entity.h"

#include "Utils/Math.h"
#include "Utils/String.h"
#include "Utils/Instrumentor.h"

#include "cmath"

using namespace IceSDK;
using namespace IceSDK::Systems;
using namespace IceSDK::Graphics;
using namespace IceSDK::Graphics::Components;

void TextRenderingSystem::Tick(float pDelta)
{
    ICESDK_PROFILE_FUNCTION();
}

void TextRenderingSystem::Draw(float pDelta)
{
    ICESDK_PROFILE_FUNCTION();
    const auto registry = this->_registry.lock();
    if (registry == nullptr)
        return;

    auto textGroup = registry->view<TextComponent>();
    for (auto rawTextEntity : textGroup)
    {
        auto textEntity = Entity(this->_registry, rawTextEntity);

        auto &text = textEntity.GetComponent<TextComponent>();
        auto &sprite = textEntity.GetComponent<SpriteComponent>();

        // Re-render text if it has changed
        if (String::CalculateHash(text.text) + text.font_size != text._old_text)
        {
            glm::vec2 resolution{};

            auto fontManager = GetGameBase()->GetFontManager();

            // Calculate texture size
            for (auto c : text.text)
            {
                auto [glyph, atlas] = fontManager->GetGlyph(text.font_face_handle, c, text.font_size);

                // TODO: center the glyphs

                resolution.x += glyph.Advance;
                resolution.y = Math::Max(resolution.y, glyph.Size.y); // Highest Height
            }

            // Create a Text Sprite
            sprite.size = resolution;
            sprite.texture = Texture2D::Create("Text: " + text.text, resolution.x, resolution.y, bgfx::TextureFormat::RGBA8);

            glm::vec2 pen{};
            // Draw glyphs
            for (auto c : text.text)
            {
                auto [glyph, atlas] = fontManager->GetGlyph(text.font_face_handle, c, text.font_size);

                // TODO: GPU acceleration using an shader and it's font atlas...
                {
                    const bgfx::Memory *memory = bgfx::alloc(glyph.PixelData.size() * 4);
                    bx::memSet(memory->data, 0, memory->size);
                    for (size_t i = 0; i < glyph.PixelData.size(); i++)
                    {
                        auto pixel = glyph.PixelData.at(i);

                        uint8_t r = (pixel.a * 0xFF), g = (pixel.a * 0xFF), b = (pixel.a * 0xFF), a = (pixel.a * 0xFF);

                        auto pixel_value = ((r & 0xFF) << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | (a & 0xFF);

                        bx::memCopy(&memory->data[i * 4], (void *)&pixel_value, 4);
                    }

                    bgfx::updateTexture2D(sprite.texture->GetHandle(), 0, 0, pen.x, pen.y, glyph.Size.x, glyph.Size.y, memory, glyph.Size.x * 4);
                }
                // TODO end

                pen.x += glyph.Advance;
            }

            text._old_text = String::CalculateHash(text.text) + text.font_size;
        }
    }
}
