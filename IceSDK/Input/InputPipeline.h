#pragma once

#include "Input/ButtonState.h"
#include "Input/KeyboardMods.h"
#include "Input/KeyboardTable.h"
#include "Input/MouseTable.h"

#include <glm/vec2.hpp>

namespace IceSDK::Input
{
    class InputPipeline
    {
    public:
        InputPipeline() = default;
        ~InputPipeline();

        void Init();

        glm::vec2 GetMouseScrollAxis() { return this->_mouse_scroll_axis; }
        glm::vec2 GetMousePosition() { return this->_mouse_move_delta; }

        KeyboardMods GetKeyboardMods() { return this->_keyboard_mods; }

        std::unordered_map<MouseTable, ButtonState> GetMouseButtonState()
        {
            return this->_mouse_state;
        }

        std::unordered_map<KeyboardTable, ButtonState> GetKeyboardButtonState()
        {
            return this->_keyboard_state;
        }

#if defined(ICESDK_SDL2)
        void PumpSDL2Event(SDL_Event& pEvent);
#endif

    private:
        glm::vec2 _mouse_scroll_axis;
        glm::vec2 _mouse_move_delta;

        KeyboardMods _keyboard_mods;

        std::unordered_map<MouseTable, ButtonState> _mouse_state;
        std::unordered_map<KeyboardTable, ButtonState> _keyboard_state;

#if defined(ICESDK_GLFW)
        static void MouseButtonCallback(GLFWwindow* pWnd, int pButton,
                                        int pButtonState, int pMods);
        static void CursorCallback(GLFWwindow* pWnd, double pX, double pY);
        static void ScrollCallback(GLFWwindow* pWnd, double pX, double pY);
        static void KeybrdCallback(GLFWwindow* pWnd, int pKey, int pScanCode,
                                   int pButtonState, int pMods);
#endif
    };
}  // namespace IceSDK::Input
