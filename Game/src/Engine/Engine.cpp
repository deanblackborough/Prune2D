#include "Engine.h"
#include <glm.hpp>
#include "../Game/Game.h"

Prune::Engine::Engine()
{
    m_EngineName = "Prune2D";
    m_EngineRunning = false;
    m_Borderless = false;
    m_Fullscreen = false;
    m_VSync = true;

    PRUNE_LOG_INFO("EngineRunning set to {0}", m_EngineRunning);
    PRUNE_LOG_INFO("Borderless set to {0}", m_Borderless);
    PRUNE_LOG_INFO("Fullscreen set to {0}", m_Fullscreen);
    PRUNE_LOG_INFO("VSync set to {0}", m_VSync);
}

Prune::Engine::~Engine()
{
}

void Prune::Engine::Down()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

void Prune::Engine::Run()
{
    Game game = Game();
    
    game.InitECS();
    game.CreateEntities();
    
    Uint32 frameEndTime = 0;

    while (m_EngineRunning)
    {
        Uint32 frameStartTime = SDL_GetTicks();
        
        CaptureEvents();
        game.CaptureEvents();
        
        double deltaTime = (frameStartTime - frameEndTime) / 1000.f;
        PRUNE_LOG_INFO("DeltaTime: {0}", deltaTime);

        game.RunSystems(deltaTime);
        Render(game);

        frameEndTime = frameStartTime;
    }
}

void Prune::Engine::Up()
{
    Engine::SDLInit();
    Engine::SDLCreateWindow();
    Engine::SDLCreateRenderer();

    entt::registry m_Registry;

    m_EngineRunning = true;
}

void Prune::Engine::CaptureEvents()
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
            }

            break;
        }
    }
}

void Prune::Engine::Render(Game& game)
{
    game.SetRenderer(m_Renderer);
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
    if (m_Fullscreen == true)
    {
        SDL_SetWindowFullscreen(m_Window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }

    PRUNE_LOG_INFO(
        "Created the SDL renderer, logical size set to width: {0}, height: {1}", 
        m_LogicalWindowWidth,
        m_LogicalWindowHeight
    );
}

void Prune::Engine::SDLCreateWindow()
{
    if (m_Fullscreen == true)
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

    if (m_Borderless == true) 
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

    PRUNE_LOG_INFO("Create the SDL window, width: {0} and height: {1}", m_WindowWidth, m_WindowHeight);
}

void Prune::Engine::SDLInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        PRUNE_LOG_CRITICAL("Failed to initialise SDL //TODO Show error");
        return;
    }

    PRUNE_LOG_INFO("Successfully initialised SDL");
}