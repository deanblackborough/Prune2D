#include "Engine.h"

Prune::Engine::Engine()
{
    m_engineName = "PruneEngine";
    m_engineRunning = false;
    m_borderless = true;
    m_fullscreen = true;

    PRUNE_LOG_INFO("Engine set to not running");
}

Prune::Engine::~Engine()
{
}

void Prune::Engine::Down()
{
    SDL_DestroyRenderer(m_renderer);
    PRUNE_LOG_INFO("Destroyed the renderer");
    SDL_DestroyWindow(m_window);
    PRUNE_LOG_INFO("Destroyed the window");
    SDL_Quit();
    PRUNE_LOG_INFO("SDL Quit");
}

void Prune::Engine::Run()
{
    while (m_engineRunning)
    {
        CaptureInputEvents();
        Render();
    }
}

void Prune::Engine::Up()
{
    Engine::SDLInit();
    Engine::SDLCreateWindow();
    Engine::SDLCreateRenderer();

    m_engineRunning = true;

    PRUNE_LOG_INFO("Engine set to running");
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
            m_engineRunning = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                PRUNE_LOG_INFO("SDLK_ESCAPE event captured - exiting");
                m_engineRunning = false;
                break;
            }

            break;
        }
    }
}

void Prune::Engine::Render()
{
    SDL_SetRenderDrawColor(
        m_renderer,
        m_windowBackgroundR,
        m_windowBackgroundG,
        m_windowBackgroundB,
        m_windowBackgroundA
    );
    SDL_RenderClear(m_renderer);



    SDL_RenderPresent(m_renderer);
}

void Prune::Engine::SDLCreateRenderer()
{
    m_renderer = SDL_CreateRenderer(
        m_window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (m_renderer == nullptr)
    {
        PRUNE_LOG_CRITICAL("Failed to create the SDL renderer //TODO show error");
        return;
    }

    SDL_RenderSetLogicalSize(m_renderer, m_logicalWindowWidth, m_logicalWindowHeight);
    if (m_fullscreen == true)
    {
        SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }

    PRUNE_LOG_INFO(
        "Created the SDL renderer, logical size set to width: {0}, height: {1}", 
        m_logicalWindowWidth,
        m_logicalWindowHeight
    );
}

void Prune::Engine::SDLCreateWindow()
{
    if (m_fullscreen == true)
    {
        SDL_DisplayMode display_mode;

        if (SDL_GetCurrentDisplayMode(0, &display_mode) != 0)
        {
            PRUNE_LOG_CRITICAL("Failed to get the display mode for the default monitor");
            return;
        }

        m_windowWidth = display_mode.w;
        m_windowHeight = display_mode.h;
    }

    Uint32 flags = SDL_WINDOW_ALLOW_HIGHDPI;

    if (m_borderless == true) 
    {
        flags |= SDL_WINDOW_BORDERLESS;
    }

    m_window = SDL_CreateWindow(
        m_engineName,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_windowWidth,
        m_windowHeight,
        flags
    );

    if (m_window == nullptr)
    {
        PRUNE_LOG_CRITICAL("Failed to create the SDL window, unknown error //TODO get error");
        return;
    }

    PRUNE_LOG_INFO("Create the SDL window, width: {0} and height: {1}", m_windowWidth, m_windowHeight);
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
