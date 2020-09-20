#pragma once
#include <cstdint>

#include "Assets/Asset.h"
#include "Graphics/Texture2D.h"
#include "Utils/Memory.h"

namespace IceSDK
{
	namespace Assets
	{
		class Texture2DAsset
		{
		public:
			explicit Texture2DAsset(const std::string &pName, const std::vector<uint8_t> &pData);

			Memory::Ptr<Graphics::Texture2D> LoadTexture() const;

			constexpr static eAssetType GetAssetType()
			{
				return eAssetType::Texture;
			}

			std::vector<uint8_t> ToByteArray() const;
			static Texture2DAsset From(const std::string &pName, const std::vector<uint8_t> &pData);

		private:
			std::string _name;
			std::vector<uint8_t> _data;
		};
	} // namespace Assets
} // namespace IceSDK
