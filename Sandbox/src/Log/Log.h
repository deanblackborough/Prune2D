#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Prune
{
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Prune2DLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_Prune2DLogger;
    };

    // Macros
    #define PRUNE_LOG_CRITICAL(...) Prune::Log::GetLogger()->critical(__VA_ARGS__);
    #define PRUNE_LOG_ERROR(...) Prune::Log::GetLogger()->error(__VA_ARGS__);
    #define PRUNE_LOG_WARNING(...) Prune::Log::GetLogger()->warn(__VA_ARGS__);
    #define PRUNE_LOG_INFO(...) Prune::Log::GetLogger()->info(__VA_ARGS__);
}
