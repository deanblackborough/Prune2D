#pragma once

#include <SDL.h>
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

        bool m_engineRunning;
        bool m_borderless;
        bool m_fullscreen;

        const char* m_engineName;

        int m_windowWidth = 800;
        int m_windowHeight = 600;

        int m_logicalWindowWidth = 800;
        int m_logicalWindowHeight = 600;

        const int m_windowBackgroundR = 80;
        const int m_windowBackgroundG = 50;
        const int m_windowBackgroundB = 185;
        const int m_windowBackgroundA = 255;

        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;

        void CaptureInputEvents();

        void Render();
        
        void SDLCreateRenderer();
        void SDLCreateWindow();
        void SDLInit();
    };
}
