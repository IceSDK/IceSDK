#pragma once

#include "ECS/Entity.h"
#include "ECS/System.h"

#include <box2d/box2d.h>
#define PHYSICS_SPEED 1.f / 60.f


#include <entt/entt.hpp>

namespace IceSDK
{
    class Scene final
    {
    public:
        explicit Scene();

        Entity CreateEntity(const std::string& pName) const;

        template<typename Sys>
        void RegisterSystem()
        {
            auto registry = Memory::WeakPtr<entt::registry>(this->_registry);
            _systems.push_back(std::make_shared<Sys>(registry));
        }

        Entity CreateCamera() const;

        void Tick(float pDelta);
        void Draw(float pDelta);

        Memory::WeakPtr<entt::registry> GetRegistry();

		b2World *GetWorld();
		b2Vec2 GetGravity() const;
		void SetGravity(const b2Vec2& gravity);

	private:
		std::vector<Memory::Ptr<System>> _systems;

		Memory::Ptr<entt::registry> _registry;

		b2Vec2 _gravity;
		b2World *_world;
	};
} // namespace IceSDK
