#pragma once

#include "Utils/Memory.h"

#include <entt/entt.hpp>

namespace IceSDK
{
    class System
    {
    public:
        explicit System(const Memory::WeakPtr<entt::registry>& pRegistry);
        virtual ~System() = default;

        virtual void Tick(float pDelta) = 0;
        virtual void Draw(float pDelta) = 0;

    protected:
        Memory::WeakPtr<entt::registry> _registry;
    };
}  // namespace IceSDK
