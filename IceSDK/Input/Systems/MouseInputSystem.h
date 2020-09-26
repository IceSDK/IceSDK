#pragma once

#include "ECS/System.h"

namespace IceSDK::Systems
{
    class MouseInputSystem final : public System
    {
    public:
        explicit MouseInputSystem(
            const Memory::WeakPtr<entt::registry>& pRegistry) :
            System(pRegistry)
        {
        }

        void Tick(float pDelta) override;
        void Draw(float pDelta) override;
    };
}  // namespace IceSDK::Systems
