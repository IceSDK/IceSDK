#pragma once

#include "ECS/System.h"

namespace IceSDK::Systems
{
    class KeyboardInputSystem final : public System
    {
    public:
        explicit KeyboardInputSystem(
            const Memory::WeakPtr<entt::registry>& pRegistry) :
            System(pRegistry)
        {
        }

        void Tick(float pDelta) override;
        void Draw(float pDelta) override;
    };
}  // namespace IceSDK::Systems
