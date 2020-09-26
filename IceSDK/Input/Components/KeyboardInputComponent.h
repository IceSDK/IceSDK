#pragma once

#include <unordered_map>

#include "Input/ButtonState.h"
#include "Input/KeyboardMods.h"
#include "Input/KeyboardTable.h"

#include <glm/vec2.hpp>

namespace IceSDK::Input::Components
{
    struct KeyboardInputComponent
    {
        KeyboardMods Mods;
        std::unordered_map<KeyboardTable, ButtonState> KeyboardState;

        bool IsPressed(KeyboardTable pBtn)
        {
            return this->KeyboardState.at(pBtn) == ButtonState::Pressed;
        }
        bool IsReleased(KeyboardTable pBtn)
        {
            return this->KeyboardState.at(pBtn) == ButtonState::Released;
        }
    };
}  // namespace IceSDK::Input::Components
