#pragma once

#include <SDL.h>
#include <entt.hpp>
#include "../Log/Log.h"

namespace Prune {
    class Engine
    {
    public:
        Engine();
        ~Engine();

        void Down();
        void Run();
        void Up();

    private:

        bool m_EngineRunning;
        bool m_Borderless;
        bool m_Fullscreen;
        bool m_VSync;

        const char* m_EngineName;

        int m_WindowWidth = 800;
        int m_WindowHeight = 600;

        int m_LogicalWindowWidth = 800;
        int m_LogicalWindowHeight = 600;

        const int m_WindowBackgroundR = 80;
        const int m_WindowBackgroundG = 50;
        const int m_WindowBackgroundB = 185;
        const int m_WindowBackgroundA = 255;

        Uint32 m_FrameStartTime = 0;
        Uint32 m_FrameEndTime = 0;

        Uint32 m_GoalFPS = 60;

        SDL_Window* m_Window = nullptr;
        SDL_Renderer* m_Renderer = nullptr;

        entt::registry m_Registry;

        void CaptureInputEvents();
        void Update();
        void Render();
        
        void SDLCreateRenderer();
        void SDLCreateWindow();
        void SDLInit();
    };
}
