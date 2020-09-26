#pragma once

#include "Utils/Memory.h"

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

namespace IceSDK
{
    class Log
    {
    public:
        static void Init();

        static Memory::Ptr<spdlog::logger>& GetCoreLogger()
        {
            return s_CoreLogger;
        }
        static Memory::Ptr<spdlog::logger>& GetClientLogger()
        {
            return s_ClientLogger;
        }

    private:
        static Memory::Ptr<spdlog::logger> s_CoreLogger;
        static Memory::Ptr<spdlog::logger> s_ClientLogger;
    };

}  // namespace IceSDK

// Core log macros
#define ICESDK_CORE_TRACE(...)                                                 \
    ::IceSDK::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ICESDK_CORE_INFO(...) ::IceSDK::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ICESDK_CORE_WARN(...) ::IceSDK::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ICESDK_CORE_ERROR(...)                                                 \
    ::IceSDK::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ICESDK_CORE_CRITICAL(...)                                              \
    ::IceSDK::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ICESDK_TRACE(...) ::IceSDK::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ICESDK_INFO(...) ::IceSDK::Log::GetClientLogger()->info(__VA_ARGS__)
#define ICESDK_WARN(...) ::IceSDK::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ICESDK_ERROR(...) ::IceSDK::Log::GetClientLogger()->error(__VA_ARGS__)
#define ICESDK_CRITICAL(...)                                                   \
    ::IceSDK::Log::GetClientLogger()->critical(__VA_ARGS__)
