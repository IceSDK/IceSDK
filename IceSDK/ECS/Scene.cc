#include "pch.h"

#include "ECS/Scene.h"

#include "ECS/Components/BaseComponent.h"
#include "ECS/Components/CameraComponent.h"

#include "ECS/Components/TransformComponent.h"
#include "ECS/Systems/TransformSystem.h"
#include "ECS/Systems/CameraSystem.h"

using namespace IceSDK;

Scene::Scene()
{
	this->_registry = std::make_shared<entt::registry>();

	CreateCamera();

	this->_world = new b2World(b2Vec2(0, 0));

	this->RegisterSystem<Systems::TransformSystem>();
	this->RegisterSystem<Systems::CameraSystem>();
}

Entity Scene::CreateEntity(const std::string &pName) const
{
	auto entity = Entity(this->_registry);

	entity.AddComponent<Components::BaseComponent>(pName, true);

	return entity;
}

Entity Scene::CreateCamera() const
{
	auto entity = this->CreateEntity("Camera");

	entity.AddComponent<Components::TransformComponent>(glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{1.0f, 1.0f, 1.0f});
	entity.AddComponent<Components::CameraComponent>(
		Components::eCameraRenderingMode::Orthographic,
		true,
		glm::vec2(0, 0),
		glm::mat4(1),
		glm::mat4(1));

	return entity;
}

void Scene::Tick(const float pDelta)
{
	// update physics worlds for this scene
	this->_world->Step(PHYSICS_SPEED, 6, 2);

	for (auto system : this->_systems)
	{
		system->Tick(pDelta);
	}
}

void Scene::Draw(const float pDelta)
{
	for (auto system : this->_systems)
	{
		system->Draw(pDelta);
	}
}

b2World* IceSDK::Scene::GetWorld()
{
	return this->_world;
}

b2Vec2 Scene::GetGravity() const
{
	return this->_gravity;
}

void Scene::SetGravity(const b2Vec2& gravity) {
	this->_gravity = gravity;
	this->_world->SetGravity(gravity);
}

Memory::WeakPtr<entt::registry> Scene::GetRegistry()
{
	return this->_registry;
}
