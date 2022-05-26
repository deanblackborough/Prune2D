#include "Engine.h"
#include <glm.hpp>
#include "../Game/Game.h"

Prune::Engine::Engine()
{
    m_EngineName = "Prune2D";
    m_EngineRunning = false;
    m_BorderlessWindow = false;
    m_FullscreenWindow = false;
    m_VSync = true;

    m_ShowBoxColliders2D = false;

    PRUNE_LOG_INFO("Setup: EngineRunning set to {0}", m_EngineRunning);
    PRUNE_LOG_INFO("Setup: Borderless set to {0}", m_BorderlessWindow);
    PRUNE_LOG_INFO("Setup: Fullscreen set to {0}", m_FullscreenWindow);
    PRUNE_LOG_INFO("Setup: VSync set to {0}", m_VSync);
    PRUNE_LOG_INFO("Debug: Show BoxColliders2D to {0}", m_ShowBoxColliders2D);
}

void Prune::Engine::Up()
{
    Engine::SDLInit();
    Engine::SDLCreateWindow();
    Engine::SDLCreateRenderer();

    entt::registry m_Registry;

    m_EngineRunning = true;
}

void Prune::Engine::Run()
{
    Game game;

    game.InitECS();
    game.SetRenderer(m_Renderer);
    game.AddSpritesToLibrary();
    game.CreateEntities();

    Uint32 frameEndTime = 0;

    while (m_EngineRunning)
    {
        Uint32 frameStartTime = SDL_GetTicks();

        CaptureInputEvents();

        double deltaTime = (frameStartTime - frameEndTime) / 1000.f;

        game.RunSystems(deltaTime);
        
        Render(game);

        frameEndTime = frameStartTime;
    }
}

void Prune::Engine::Down()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

void Prune::Engine::CaptureInputEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            PRUNE_LOG_INFO("SDL_QUIT event captured - exiting");
            m_EngineRunning = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                PRUNE_LOG_INFO("SDLK_ESCAPE event captured - exiting");
                m_EngineRunning = false;
                break;
            case SDLK_d:
                m_ShowBoxColliders2D = !m_ShowBoxColliders2D;
                PRUNE_LOG_INFO("Debug: Show box colliders 2d toggled, setting set to {0}", m_ShowBoxColliders2D);
                break;
            }

            break;
        }
    }
}

void Prune::Engine::Render(Game& game)
{
    // Set any debug settings
    game.SetShowBoxColliders2D(m_ShowBoxColliders2D);

    game.RenderBackground();
    game.RenderEntities();

    SDL_RenderPresent(m_Renderer);
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
