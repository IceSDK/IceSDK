#include "pch.h"

#include "Utils/Instrumentor.h"

#include "Physics/PhysicsSystem.h"

#include "ECS/Entity.h"
#include "ECS/Components/RigidbodyComponent.h"
#include "ECS/Components/TransformComponent.h"

#include "Utils/Logger.h"

using namespace IceSDK::Systems::Physics;
using namespace IceSDK::Components;

PhysicsSystem::PhysicsSystem(const Memory::WeakPtr<entt::registry>& pRegistry) : System(pRegistry)
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
	if (registry == nullptr)
		return;

	auto physicsGroup = registry->view<RigidbodyComponent>();
	for (auto rawPhysicsEntity : physicsGroup) {
		auto physicsEntity = Entity(this->_registry, rawPhysicsEntity);

		auto& rigidbody = physicsEntity.GetComponent<RigidbodyComponent>();

		if (!rigidbody.body)
			return;

		auto& transform = physicsEntity.GetComponent<TransformComponent>();
		transform.position.y = rigidbody.body->GetPosition().y;
		transform.position.x = rigidbody.body->GetPosition().x;
	}
}