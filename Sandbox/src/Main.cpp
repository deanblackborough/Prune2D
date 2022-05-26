#include <iostream>
#include "Log/Log.h"
#include "Engine/Engine.h"

int main(int argc, char* argv[])
{
    Prune::Log::Init();
    PRUNE_LOG_INFO("Logger started");

    Prune::Engine engine;

    engine.Up();
    engine.Run();
    engine.Down();

    return 0;
}
