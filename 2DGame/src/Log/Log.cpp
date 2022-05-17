#include "Log.h"

std::shared_ptr<spdlog::logger> Prune::Log::s_EngineLogger;

void Prune::Log::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_EngineLogger = spdlog::stderr_color_mt("Engine");
    s_EngineLogger->set_level(spdlog::level::trace);
}
