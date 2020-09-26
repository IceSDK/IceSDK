#include "pch.h"

#include "Utils/Logger.h"

using namespace IceSDK;

Memory::Ptr<spdlog::logger> Log::s_CoreLogger;
Memory::Ptr<spdlog::logger> Log::s_ClientLogger;

static bool g_LoggerInitialized = false;

void Log::Init()
{
    if (g_LoggerInitialized) return;

    std::vector<spdlog::sink_ptr> logSinks;
#ifdef ICESDK_ANDROID
    logSinks.emplace_back(std::make_shared<spdlog::sinks::android_sink_mt>());
#endif

#ifndef ICESDK_ANDROID
    logSinks.emplace_back(
        std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(
        "IceSDK.log", true));
    logSinks[1]->set_pattern("[%T] [%l] %n: %v");
#endif

    logSinks[0]->set_pattern("%t\t[%T] [%n]\t[%5^%l%$]: %v");

    s_CoreLogger = std::make_shared<spdlog::logger>("ICESDK", begin(logSinks),
                                                    end(logSinks));
    spdlog::register_logger(s_CoreLogger);
    s_CoreLogger->set_level(spdlog::level::trace);
    s_CoreLogger->flush_on(spdlog::level::trace);

    s_ClientLogger =
        std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
    spdlog::register_logger(s_ClientLogger);
    s_ClientLogger->set_level(spdlog::level::trace);
    s_ClientLogger->flush_on(spdlog::level::trace);

    g_LoggerInitialized = true;
}
