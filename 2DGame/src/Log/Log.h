#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Engine
{
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_EngineLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
    };

    // Macros
    #define ENGINE_LOG_CRITICAL(...) Engine::Log::GetLogger()->critical(__VA_ARGS__);
    #define ENGINE_LOG_ERROR(...) Engine::Log::GetLogger()->error(__VA_ARGS__);
    #define ENGINE_LOG_WARNING(...) Engine::Log::GetLogger()->warn(__VA_ARGS__);
    #define ENGINE_LOG_INFO(...) Engine::Log::GetLogger()->info(__VA_ARGS__);
}
