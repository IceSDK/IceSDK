#pragma once

#include "Assets/AssetHeader.h"

#include <string>
#include <vector>

namespace IceSDK::Assets
{
    class TextAsset
    {
    public:
        explicit TextAsset(std::string pData);

        std::string ToString() const;

        constexpr static eAssetType GetAssetType() { return eAssetType::Text; }

        std::vector<uint8_t> ToByteArray();
        static TextAsset From(std::string pName, std::vector<uint8_t> pData);

    private:
        std::string _data;
    };
}  // namespace IceSDK::Assets
