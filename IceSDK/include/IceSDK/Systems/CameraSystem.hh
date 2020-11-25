#pragma once

#include "IceSDK/Entity.hh"
#include "IceSDK/System.hh"

#include <entt/entt.hpp>

#include <memory>

namespace IceSDK::Systems
{
    class CameraSystem final : public System
    {
    public:
        explicit CameraSystem(const std::weak_ptr<entt::registry>& wpRegistry) :
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

        /*****************************************************
         * GetActiveCamera
         *
         * Gets the current active camera entity.
         *
         * @param fDelta Current active camera entity
         *****************************************************/
        static Entity GetActiveCamera(
            const std::weak_ptr<entt::registry> wpRegistry);
    };
}  // namespace IceSDK::Systems
