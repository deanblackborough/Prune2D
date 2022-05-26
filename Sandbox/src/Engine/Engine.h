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
        ~Engine() = default;

        void Up();
        void Run();
        void Down();

    private:

        bool m_EngineRunning;
        bool m_BorderlessWindow;
        bool m_FullscreenWindow;
        bool m_VSync;

        const char* m_EngineName;

        int m_WindowWidth = 800;
        int m_WindowHeight = 600;

        int m_LogicalWindowWidth = 800;
        int m_LogicalWindowHeight = 600;

        SDL_Window* m_Window = nullptr;
        SDL_Renderer* m_Renderer = nullptr;

        entt::registry m_Registry;

        void CaptureInputEvents();
        void Render(Game& game);
        
        void SDLCreateRenderer();
        void SDLCreateWindow();
        void SDLInit();
    };
}
