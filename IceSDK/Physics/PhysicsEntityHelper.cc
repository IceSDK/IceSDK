#include "pch.h"

#include "ECS/Components/BaseComponent.h"
#include "ECS/Components/TransformComponent.h"
#include "ECS/Scene.h"

#include "Utils/Instrumentor.h"
#include "Utils/Logger.h"

#include "Graphics/Components/SpriteComponent.h"
#include "Physics/Components/RigidbodyComponent.h"
#include "Physics/EntityHelper.h"
#include "Physics/Systems/PhysicsSystem.h"

using namespace IceSDK;
using namespace IceSDK::Physics;
using namespace IceSDK::Physics::Entity;

void IceSDK::Physics::Entity::AttachPhysicsObject(
    Memory::Ptr<IceSDK::Scene> pScene, IceSDK::Entity target)
{
    auto& transform =
        target.GetComponent<IceSDK::Components::TransformComponent>();

    IceSDK::Components::RigidbodyComponent phys_comp;
    phys_comp.body_def.type = b2_dynamicBody;
    phys_comp.body_def.angle = glm::radians(transform.rotation);

    phys_comp.body_def.position =
        b2Vec2(transform.position.x / PPM, transform.position.y / PPM);

    phys_comp.body = pScene->GetWorld()->CreateBody(&phys_comp.body_def);

    ICESDK_CORE_INFO("X: {} Y: {}", (transform.scale.x / PPM) * .5,
                     (transform.scale.y / PPM) * .5);

    // TODO
    phys_comp.shape.SetAsBox((transform.scale.x / PPM) * .5,
                             (transform.scale.y / PPM) * .5);

    b2FixtureDef
        fixtureDef;  // TODO - make these settings are editable (by scene)
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;
    fixtureDef.restitution = 0.5f;

    fixtureDef.shape = &phys_comp.shape;

    phys_comp.body->CreateFixture(&fixtureDef);

    target.AddComponent<IceSDK::Components::RigidbodyComponent>(phys_comp);
}

void IceSDK::Physics::Entity::AttachSolidPhysicsObject(
    Memory::Ptr<IceSDK::Scene> pScene, IceSDK::Entity target)
{
    auto& transform =
        target.GetComponent<IceSDK::Components::TransformComponent>();

    IceSDK::Components::RigidbodyComponent phys_comp;
    phys_comp.body_def.type = b2_staticBody;
    phys_comp.body_def.angle = glm::radians(transform.rotation);

    phys_comp.body_def.position =
        b2Vec2(transform.position.x / PPM, transform.position.y / PPM);
    phys_comp.body = pScene->GetWorld()->CreateBody(&phys_comp.body_def);

    // TODO
    phys_comp.shape.SetAsBox((transform.scale.x / PPM),
                             (transform.scale.y / PPM) * .5);

    phys_comp.body->CreateFixture(&phys_comp.shape, 0.f);

    target.AddComponent<IceSDK::Components::RigidbodyComponent>(phys_comp);
}

void Physics::Entity::InitScene(const Memory::Ptr<IceSDK::Scene>& pScene)
{
    ICESDK_PROFILE_FUNCTION();

    pScene->RegisterSystem<Systems::Physics::PhysicsSystem>();
}
