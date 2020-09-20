#include "pch.h"

#include "Assets/AssetManager.h"

#include "Assets/TextAsset.h"
#include "Assets/AudioAsset.h"
#include "Assets/Texture2DAsset.h"

#include "Utils/FileSystem.h"
#include "Utils/Instrumentor.h"
#include "Utils/Logger.h"

using namespace IceSDK;
using namespace IceSDK::Assets;

void AssetManager::Init()
{
	ICESDK_PROFILE_FUNCTION();
	if (!FileSystem::Exists("./Assets"))
		return;

	for (const auto &assetFilePath : FileSystem::ReadDirectory("./Assets"))
	{
		if (FileSystem::IsDirectory(assetFilePath))
			continue;

		auto assetFile = AssetFile::Load(assetFilePath);
		if (assetFile == nullptr)
		{
			ICESDK_CORE_CRITICAL("Failed to initialize AssetManager");
			break;
		}

		this->_assets.push_back(assetFile);
	}
}

Memory::Ptr<Graphics::Texture2D> AssetManager::LoadTexture(const std::string &pName)
{
	auto asset = this->Search(pName);
	if (asset.data.empty()) // Null objects aren't acceptable.
		return nullptr;

	return asset.Into<Texture2DAsset>(pName).LoadTexture();
}

Memory::Ptr<Audio::Sound> AssetManager::LoadAudio(const std::string &pName)
{
	auto asset = this->Search(pName);

	return asset.Into<AudioAsset>(pName).LoadAudio();
}

std::string AssetManager::LoadText(const std::string &pName)
{
	auto asset = this->Search(pName);

	return asset.Into<TextAsset>(pName).ToString();
}

Asset AssetManager::Search(const std::string &pName)
{
	if (this->_search_cache.count(pName))
		return this->_search_cache[pName];

	for (auto assetFile : this->_assets)
	{
		auto asset = assetFile->Get(pName);
		if (asset.asset_type != eAssetType::Unknown)
		{
			this->_search_cache[pName] = asset;
			return asset;
		}
	}

	this->_search_cache[pName] = {}; // Insert empty key

	return {};
}

std::vector<Memory::Ptr<AssetFile>> &AssetManager::GetAll()
{
	return this->_assets;
}
