#pragma once

#include "Graphics/Texture2D.h"
#include "Graphics/Fonts/FontManager.h"
#include "Graphics/Shaders/ShaderManager.h"

#include "ECS/Scene.h"
#include "ECS/Entity.h"

namespace IceSDK::Graphics::Entity
{
	void Init(const Memory::Ptr<Graphics::Shaders::ShaderManager> &pShaderManager);
	void InitScene(const Memory::Ptr<IceSDK::Scene> &pScene);

	IceSDK::Entity CreateSprite(
		Memory::Ptr<IceSDK::Scene> pScene,
		Memory::Ptr<Shaders::ShaderManager> pShaderManager,
		Memory::Ptr<Texture2D> pTex);

	IceSDK::Entity CreateText(
		Memory::Ptr<IceSDK::Scene> pScene,
		Memory::Ptr<Shaders::ShaderManager> pShaderManager,
		const std::string &pText, size_t pFontSize, FontFaceHandle pFontFace);
} // namespace IceSDK::Graphics::Entity
