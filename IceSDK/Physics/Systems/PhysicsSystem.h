#pragma once

#include "ECS/System.h"

#include <box2d/box2d.h>

namespace IceSDK::Systems
{
    namespace Physics
    {
        class PhysicsSystem final : public System
        {
        public:
            explicit PhysicsSystem(
                const Memory::WeakPtr<entt::registry>& pRegistry);

            void Draw(float pDelta) override;
            void Tick(float pDelta) override;
        };
    }  // namespace Physics
}  // namespace IceSDK::Systems
