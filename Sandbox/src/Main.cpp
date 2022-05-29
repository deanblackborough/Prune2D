#include <iostream>
#include "Log/Log.h"
#include "Engine/Engine.h"

int main(int argc, char* argv[])
{
    Prune::Log::Init();

    Prune::Engine engine;
    Prune::Game game;

    engine.Up();

    game.SetRenderer(engine.GetRenderer());
    game.Run();

    engine.Down();

    return 0;
}
