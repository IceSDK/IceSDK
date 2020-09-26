#pragma once

#include "ECS/Entity.h"
#include "ECS/Scene.h"

#include "Graphics/Fonts/FontManager.h"
#include "Graphics/Shaders/ShaderManager.h"
#include "Graphics/Texture2D.h"

#include <glm/glm.hpp>

namespace IceSDK::Physics::Entity
{
    void InitScene(const Memory::Ptr<IceSDK::Scene>& pScene);

    void AttachPhysicsObject(Memory::Ptr<IceSDK::Scene> pScene,
                             IceSDK::Entity target);

    void AttachSolidPhysicsObject(Memory::Ptr<IceSDK::Scene> pScene,
                                  IceSDK::Entity target);
}  // namespace IceSDK::Physics::Entity
