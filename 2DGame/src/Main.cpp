#include <iostream>
#include "Log/Log.h"

int main(int argc, char* argv[])
{
    Engine::Log::Init();
    ENGINE_LOG_INFO("Logging a message to the logger");

    std::cout << "This is a test" << std::endl;

    return 0;
}