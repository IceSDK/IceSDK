#include "pch.h"

#include "Input/InputPipeline.h"

#include "Utils/Logger.h"

#include "GameBase.h"

using namespace IceSDK;
using namespace IceSDK::Input;

static InputPipeline* g_InputPipeline;

#if defined(ICESDK_GLFW)
void InputPipeline::MouseButtonCallback(GLFWwindow* pWnd, int pButton,
                                        int pButtonState, int pMods)
{
    auto inputPipeline = GetGameBase()->GetInputPipeline();

    inputPipeline->_mouse_state.insert_or_assign((MouseTable) pButton,
                                                 (ButtonState) pButtonState);
}

void InputPipeline::CursorCallback(GLFWwindow* pWnd, double pX, double pY)
{
    auto inputPipeline = GetGameBase()->GetInputPipeline();

    inputPipeline->_mouse_move_delta.x = pX;
    inputPipeline->_mouse_move_delta.y = pY;
}

void InputPipeline::ScrollCallback(GLFWwindow* pWnd, double pX, double pY)
{
    auto inputPipeline = GetGameBase()->GetInputPipeline();

    inputPipeline->_mouse_scroll_axis.x = pX;
    inputPipeline->_mouse_scroll_axis.y = pY;
}

void InputPipeline::KeybrdCallback(GLFWwindow* pWnd, int pKey, int pScanCode,
                                   int pButtonState, int pMods)
{
    auto inputPipeline = GetGameBase()->GetInputPipeline();

    inputPipeline->_keyboard_mods = (KeyboardMods) pMods;
    inputPipeline->_keyboard_state.insert_or_assign((KeyboardTable) pKey,
                                                    (ButtonState) pButtonState);
}
#endif

void InputPipeline::Init()
{
    auto nativeWindow = GetWindow()->GetNativeWindow();

#if defined(ICESDK_GLFW)
    glfwSetInputMode(nativeWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    glfwSetMouseButtonCallback(nativeWindow,
                               InputPipeline::MouseButtonCallback);
    glfwSetCursorPosCallback(nativeWindow, InputPipeline::CursorCallback);
    glfwSetScrollCallback(nativeWindow, InputPipeline::ScrollCallback);
    glfwSetKeyCallback(nativeWindow, InputPipeline::KeybrdCallback);

#endif
}

InputPipeline::~InputPipeline()
{
    auto nativeWindow = GetWindow()->GetNativeWindow();

    if (nativeWindow != nullptr)
    {
        glfwSetCursorPosCallback(nativeWindow, NULL);
        glfwSetScrollCallback(nativeWindow, NULL);
        glfwSetKeyCallback(nativeWindow, NULL);
    }
}
