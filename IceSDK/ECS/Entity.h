#pragma once

#include "Utils/Memory.h"

#include <entt/entt.hpp>

namespace IceSDK
{
    class Entity final
    {
    public:
        explicit Entity(const Memory::WeakPtr<entt::registry>& pRegistry);
        explicit Entity(const Memory::WeakPtr<entt::registry>& pRegistry,
                        entt::entity pEntity);
        explicit Entity();

        template<typename T>
        bool HasComponent()
        {
            return this->_registry.lock()->has<T>(this->_inner);
        }

        template<typename T, typename... Args>
        T& AddComponent(Args&&... pArgs)
        {
            const auto registry = this->_registry.lock();

            return registry->emplace<T>(this->_inner,
                                        std::forward<Args>(pArgs)...);
        }

        template<typename T>
        T& GetComponent()
        {
            const auto registry = this->_registry.lock();
            return registry->get<T>(this->_inner);
        }

        template<typename T>
        bool RemoveComponent(T pComponent)
        {
            if (!this->HasComponent(pComponent)) return false;

            const auto registry = this->_registry.lock();
            registry->remove_all(this->_inner, pComponent);

            return true;
        }

        static bool IsValid(const Entity& pEntity);

    private:
        Memory::WeakPtr<entt::registry> _registry;
        entt::entity _inner = entt::null;
    };
}  // namespace IceSDK