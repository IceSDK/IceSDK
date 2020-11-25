#pragma once

#include "IceSDK/System.hh"

#include <memory>

namespace IceSDK::Systems
{
    class SpriteRenderingSystem final : public System
    {
    public:
        explicit SpriteRenderingSystem(
            const std::weak_ptr<entt::registry>& wpRegistry) :
            System(wpRegistry)
        {
        }

        /*****************************************************
         * Init
         *
         * Initializes all the sprite rendering.
         *****************************************************/
        static void Init();

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
