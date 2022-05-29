#include "Engine.h"
#include <glm.hpp>
#include "../Game/Game.h"

Prune::Engine::Engine()
{
    m_EngineName = "Prune2D";
    m_BorderlessWindow = false;
    m_FullscreenWindow = false;
    m_VSync = true;

    PRUNE_LOG_INFO("Setup: Borderless set to {0}", m_BorderlessWindow);
    PRUNE_LOG_INFO("Setup: Fullscreen set to {0}", m_FullscreenWindow);
    PRUNE_LOG_INFO("Setup: VSync set to {0}", m_VSync);
}

void Prune::Engine::Up()
{
    Engine::SDLInit();
    Engine::SDLCreateWindow();
    Engine::SDLCreateRenderer();

    entt::registry m_Registry;
}

void Prune::Engine::Down()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

SDL_Renderer* Prune::Engine::GetRenderer()
{
    return m_Renderer;
}

void Prune::Engine::SDLCreateRenderer()
{
    Uint32 flags = SDL_RENDERER_ACCELERATED;
    if (m_VSync == true) {
        flags |= SDL_RENDERER_PRESENTVSYNC;
    }
    m_Renderer = SDL_CreateRenderer(
        m_Window,
        -1,
        flags
    );

    if (m_Renderer == nullptr)
    {
        PRUNE_LOG_CRITICAL("Failed to create the SDL renderer //TODO show error");
        return;
    }

    SDL_RenderSetLogicalSize(m_Renderer, m_LogicalWindowWidth, m_LogicalWindowHeight);
    if (m_FullscreenWindow == true)
    {
        SDL_SetWindowFullscreen(m_Window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
}

void Prune::Engine::SDLCreateWindow()
{
    if (m_FullscreenWindow == true)
    {
        SDL_DisplayMode display_mode;

        if (SDL_GetCurrentDisplayMode(0, &display_mode) != 0)
        {
            PRUNE_LOG_CRITICAL("Failed to get the display mode for the default monitor");
            return;
        }

        m_WindowWidth = display_mode.w;
        m_WindowHeight = display_mode.h;
    }

    Uint32 flags = SDL_WINDOW_ALLOW_HIGHDPI;

    if (m_BorderlessWindow == true) 
    {
        flags |= SDL_WINDOW_BORDERLESS;
    }

    m_Window = SDL_CreateWindow(
        m_EngineName,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_WindowWidth,
        m_WindowHeight,
        flags
    );

    if (m_Window == nullptr)
    {
        PRUNE_LOG_CRITICAL("Failed to create the SDL window, unknown error //TODO get error");
        return;
    }
}

void Prune::Engine::SDLInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        PRUNE_LOG_CRITICAL("Failed to initialise SDL //TODO Show error");
        return;
    }
}
