#include "pch.h"

#include "GameBase.h"

#include "Graphics/Fonts/FontManager.h"
#include "Graphics/Components/TextComponent.h"
#include "Graphics/Components/SpriteComponent.h"
#include "Graphics/Systems/TextRenderingSystem.h"

#include "ECS/Entity.h"

#include "Utils/String.h"
#include "Utils/Instrumentor.h"

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
        if (String::CalculateHash(text.text) != text._old_text)
        {
            glm::vec2 resolution;

            auto fontManager = GetGameBase()->GetFontManager();

            // Calculate texture size
            for (auto &c : text.text)
            {
                auto glyph = fontManager->GetGlyph(c);

                // TODO: center the glyphs

                //resolution.x = glm::max(resolution.x, 2); // Highest Width
                //resolution.y = glm::max(resolution.y, 2); // Highest Height
            }

            text._old_text = String::CalculateHash(text.text);
        }
    }
}
