#pragma once

#include "IceSDK/System.hh"

#include <memory>

namespace IceSDK::Systems
{
    class TextRenderingSystem final : public System
    {
    public:
        explicit TextRenderingSystem(
            const std::weak_ptr<entt::registry>& wpRegistry) :
            System(wpRegistry)
        {
        }

        /*****************************************************
         * Tick
         *
         * Tick the current system
         *
         * @param fDelta Delta time between the last tick
         *****************************************************/
        void Tick(float fDelta) override;

        /*****************************************************
         * Draw
         *
         * Draws the current system
         *
         * @param fDelta Delta time between the last draw
         *****************************************************/
        void Draw(float fDelta) override;
    };
}  // namespace IceSDK::Systems
