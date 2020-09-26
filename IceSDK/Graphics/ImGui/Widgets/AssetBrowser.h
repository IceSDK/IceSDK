#pragma once

#include "Assets/AssetManager.h"

#include "Utils/Memory.h"

namespace IceSDK::ImGuiWidgets::AssetBrowser
{
    void Init(Memory::Ptr<Assets::AssetManager> pManager);
    void Frame(Memory::Ptr<Assets::AssetManager> pManager);
}  // namespace IceSDK::ImGuiWidgets::AssetBrowser
