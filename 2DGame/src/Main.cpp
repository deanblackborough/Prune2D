#include <iostream>
#include "Log/Log.h"

int main(int argc, char* argv[])
{
    Prune::Log::Init();
    PRUNE_LOG_INFO("Logging a message to the logger");

    std::cout << "This is a test" << std::endl;

    return 0;
}