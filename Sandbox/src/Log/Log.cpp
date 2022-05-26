#include "Log.h"

std::shared_ptr<spdlog::logger> Prune::Log::s_Prune2DLogger;

void Prune::Log::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_Prune2DLogger = spdlog::stderr_color_mt("Prune2D");
    s_Prune2DLogger->set_level(spdlog::level::trace);
}
