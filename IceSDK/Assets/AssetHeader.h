#pragma once

#include <cstdint>

namespace IceSDK::Assets
{
    constexpr auto asset_magic_value = 0x53464C45584950;
    constexpr auto asset_version = 0x0001;
    constexpr auto asset_register_size = 256;
    constexpr auto asset_name_length = 128;

    enum class eAssetType : uint8_t
    {
        Unknown = 0,

        Texture = 1,
        AnimatedTexture = 2,
        Audio = 3,
        Video = 4,
        Particle = 5,

        Shader = 6,

        Text = 7
    };

    struct AssetRegion
    {
        eAssetType type = eAssetType::Unknown;
        uint32_t size = 0;
        char name[asset_name_length]{};
    };

    struct AssetHeader
    {
        uint64_t magic_value = asset_magic_value;
        uint16_t version = asset_version;

        AssetRegion asset_register[asset_register_size];
    };
}  // namespace IceSDK::Assets
