#include "pch.h"

#include "Assets/AssetFile.h"

#include "Utils/FileSystem.h"
#include "Utils/Instrumentor.h"
#include "Utils/Logger.h"

using namespace IceSDK;
using namespace IceSDK::Assets;

bool AssetFile::IsFull() const
{
    return this->GetEmptyEntry() == -1;
}

Asset AssetFile::Get(const std::string& pName)
{
    const auto index = GetIndex(pName);
    if (index == -1) return {};

    return this->Get(static_cast<uint32_t>(index));
}

Asset AssetFile::Get(const uint32_t pIndex)
{
    ICESDK_PROFILE_FUNCTION();
    auto pos = 0;
    for (uint32_t i = 0; i < asset_register_size; ++i)
    {
        if (i == pIndex) break;

        pos += this->header.asset_register[i].size;
    }

    const auto region = this->header.asset_register[pIndex];
    const auto data = std::vector<uint8_t>(
        this->body.begin() + pos, this->body.begin() + pos + region.size);

    return Asset{ region.type, data };
}

int32_t AssetFile::GetIndex(const std::string& pName) const
{
    ICESDK_PROFILE_FUNCTION();
    for (auto i = 0; i < asset_register_size; ++i)
    {
        if (this->header.asset_register[i].name == pName) return i;
    }

    return -1;
}

void AssetFile::Append(const std::string& pName, const Asset& pAsset)
{
    ICESDK_PROFILE_FUNCTION();
    assert(pName.length() <= asset_name_length);

    const auto register_index = GetEmptyEntry();
    if (register_index == -1) return;  // Full TODO: throw an error!

    auto pos = 0;  // Figure out the correct position for the to write to.
    for (const auto& region : this->header.asset_register) pos += region.size;

    auto* region = &this->header.asset_register[register_index];
    memcpy(&region->name[0], &pName[0], pName.size() + 1);

    region->type = pAsset.asset_type;
    region->size = static_cast<uint32_t>(pAsset.data.size());

    this->body.resize(pos + pAsset.data.size());
    memcpy(&this->body[0] + pos, &pAsset.data[0], pAsset.data.size());
}

void AssetFile::Save(const std::string& pPath)
{
    ICESDK_PROFILE_FUNCTION();
    std::vector<uint8_t> data;
    data.resize(sizeof(AssetHeader) + this->body.size());

    memcpy(&data[0], &this->header, sizeof(AssetHeader));
    memcpy(&data[0] + sizeof(AssetHeader), &this->body[0], body.size());

    FileSystem::WriteBinaryFile(pPath, data);
}

Memory::Ptr<AssetFile> AssetFile::Load(const std::vector<uint8_t>& pMemory)
{
    ICESDK_PROFILE_FUNCTION();
    auto file = std::make_shared<AssetFile>();  // Our AssetFile is too big to
                                                // be stored in our stack
    {
        memcpy(&file->header, &pMemory[0], sizeof(AssetHeader));

        const auto size =
            -(pMemory.begin() + sizeof(AssetHeader) - pMemory.end());
        file->body.resize(size);
        memcpy(&file->body[0], &pMemory[0] + sizeof(AssetHeader), size);
    }
    return file;
}

Memory::Ptr<AssetFile> AssetFile::Load(const std::string& pPath)
{
    ICESDK_PROFILE_FUNCTION();
    auto data = FileSystem::ReadBinaryFile(pPath);

    if (data.empty())
    {
        ICESDK_CORE_ERROR("Failed to load AssetFile: {}!", pPath);
        return nullptr;
    }

    ICESDK_CORE_INFO("{}: {}", pPath, data.size());

    return AssetFile::Load(data);
}

int32_t AssetFile::GetEmptyEntry() const
{
    ICESDK_PROFILE_FUNCTION();
    for (auto i = 0; i < asset_register_size; ++i)
    {
        if (this->header.asset_register[i].size <= 0) return i;
    }

    return -1;
}
