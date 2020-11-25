#pragma once

#include "IceSDK/System.hh"

namespace IceSDK::Systems
{
    class KeyboardInputSystem final : public System
    {
    public:
        explicit KeyboardInputSystem(
            const std::weak_ptr<entt::registry>& fRegistry) :
            System(fRegistry)
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
