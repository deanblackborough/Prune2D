#pragma once

#include <SDL.h>
#include <entt.hpp>
#include "../Log/Log.h"
#include "../Game/Game.h"

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
        Uint32 m_GoalFPS;

        const char* m_EngineName;

        int m_WindowWidth = 800;
        int m_WindowHeight = 600;

        int m_LogicalWindowWidth = 800;
        int m_LogicalWindowHeight = 600;

        Uint32 m_FrameEndTime = 0;

        SDL_Window* m_Window = nullptr;
        SDL_Renderer* m_Renderer = nullptr;

        entt::registry m_Registry;

        void CaptureInputEvents();
        void Update(Game& game);
        void Render(Game& game);
        
        void SDLCreateRenderer();
        void SDLCreateWindow();
        void SDLInit();
    };
}
