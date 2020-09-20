#pragma once

#ifdef ICESDK_WIN32
#include "Windows.h"
#endif

#ifdef ICESDK_EMSCRIPTEN
#include "emscripten.h"
#endif

#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/allocator.h"

#include "bx/bx.h"
#include "bx/timer.h"

#include "bimg/bimg.h"
#include "bimg/decode.h"

#include "entt/entt.hpp"

#ifdef ICESDK_FMOD
#include "fmod_errors.h"
#include "fmod.hpp"
#include "fmod.h"
#endif

#ifdef ICESDK_GLFW

#ifdef ICESDK_WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#elif ICESDK_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#endif

#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#endif

#ifdef ICESDK_SDL2
#include "SDL.h"
#include "SDL_syswm.h"
#endif

// This is stupid... don't name thins "None" as a #define
#ifdef ICESDK_LINUX
#undef None
#endif

#if ICESDK_ANDROID
#include "GLES/egl.h"
#endif

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

#ifdef ICESDK_SDL2
#include "imgui_impl_sdl.h"
#elif defined(ICESDK_GLFW)
#include "imgui_impl_glfw.h"
#endif
#include "imgui_internal.h"
#include "imgui.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/android_sink.h"

#include "ft2build.h"
#include FT_FREETYPE_H

#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <memory>
#include <vector>
#include <string>
