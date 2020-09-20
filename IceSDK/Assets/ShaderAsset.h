#pragma once

#include <vector>

#include "Assets/Asset.h"
#include "Utils/Memory.h"
#include "Graphics/Shaders/ShaderManager.h"

#include "bgfx/bgfx.h"

namespace IceSDK
{
	namespace Assets
	{
		class ShaderAsset
		{
		public:
			// Memory::Ptr<Audio::Audio> LoadAudio() const;

			constexpr static eAssetType GetAssetType()
			{
				return eAssetType::Shader;
			}

			std::vector<uint8_t> ToByteArray() const;
			static ShaderAsset From(std::string pName, std::vector<uint8_t> pData);

		private:
			struct Shader
			{
				Graphics::Shaders::eShaderType type;
				bgfx::RendererType::Enum platform;
				std::vector<uint8_t> code;
			};

			std::vector<Shader> _shaders{};
		};

	} // namespace Assets
} // namespace IceSDK
