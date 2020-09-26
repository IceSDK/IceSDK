#pragma once

#include <unordered_map>

#include "Assets/AssetFile.h"
#include "Audio/Sound.h"

#include "Utils/Memory.h"

#include "Graphics/Texture2D.h"

#include <vector>

#ifdef ICESDK_EMSCRIPTEN
    #include <emscripten/fetch.h>
#endif

namespace IceSDK::Assets
{
    class AssetManager
    {
    public:
        void Init();  // Load all asset files into memory
                      //	TODO:	Don't do that
                      //	TODO:	make it faster for low end devices!

        Memory::Ptr<Graphics::Texture2D> LoadTexture(const std::string& pName);

        Memory::Ptr<Audio::Sound> LoadAudio(const std::string& pName);

        std::string LoadText(const std::string& pName);

        std::vector<Memory::Ptr<AssetFile>>& GetAll();

    private:
        Asset Search(const std::string& pName);

        std::unordered_map<std::string, Asset> _search_cache;
        std::vector<Memory::Ptr<AssetFile>> _assets;
    };
}  // namespace IceSDK::Assets
