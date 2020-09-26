#pragma once

#include "Assets/AssetHeader.h"
#include "Audio/AudioSystem.h"

#include <vector>

namespace IceSDK::Assets
{
    class AudioAsset
    {
    public:
        explicit AudioAsset(std::vector<uint8_t> pData);

        Memory::Ptr<Audio::Sound> LoadAudio() const;

        constexpr static eAssetType GetAssetType() { return eAssetType::Audio; }

        std::vector<uint8_t> ToByteArray() const;
        static AudioAsset From(std::string pName, std::vector<uint8_t> pData);

    private:
        std::vector<uint8_t> _data{};
    };
}  // namespace IceSDK::Assets
