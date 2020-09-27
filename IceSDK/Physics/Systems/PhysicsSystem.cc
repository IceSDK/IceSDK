#include "pch.h"

#include "Physics/Systems/PhysicsSystem.h"

#include "ECS/Components/TransformComponent.h"
#include "ECS/Entity.h"

#include "Utils/Instrumentor.h"
#include "Utils/Logger.h"

#include "Physics/Components/RigidbodyComponent.h"
#include "Physics/EntityHelper.h"

using namespace IceSDK::Systems::Physics;
using namespace IceSDK::Components;

PhysicsSystem::PhysicsSystem(const Memory::WeakPtr<entt::registry>& pRegistry) :
    System(pRegistry)
{
}

void PhysicsSystem::Draw(float pDelta)
{
    ICESDK_PROFILE_FUNCTION();
}

void PhysicsSystem::Tick(float timeStep)
{
    ICESDK_PROFILE_FUNCTION();
    const auto registry = this->_registry.lock();
    if (registry == nullptr) return;

    auto physicsGroup = registry->view<RigidbodyComponent>();
    for (auto rawPhysicsEntity : physicsGroup)
    {
        auto physicsEntity = Entity(this->_registry, rawPhysicsEntity);

        auto& rigidbody = physicsEntity.GetComponent<RigidbodyComponent>();

        if (!rigidbody.body) return;

        auto& transform = physicsEntity.GetComponent<TransformComponent>();
        transform.position.y = rigidbody.body->GetPosition().y * PPM;
        transform.position.x = rigidbody.body->GetPosition().x * PPM;
        transform.rotation = glm::degrees(rigidbody.body->GetAngle());
    }
}
