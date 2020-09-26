#include "pch.h"

#include "ECS/System.h"

using namespace IceSDK;

System::System(const Memory::WeakPtr<entt::registry>& pRegistry)
{
    this->_registry = pRegistry;
}
