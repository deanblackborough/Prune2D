#include "Log.h"

std::shared_ptr<spdlog::logger> Engine::Log::s_EngineLogger;

void Engine::Log::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_EngineLogger = spdlog::stderr_color_mt("Engine");
    s_EngineLogger->set_level(spdlog::level::trace);
}
