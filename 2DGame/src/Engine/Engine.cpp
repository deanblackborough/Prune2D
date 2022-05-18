#include "Engine.h"
#include <glm.hpp>

struct TransformComponent 
{
    glm::vec2 transform = glm::vec2(0, 0);
    glm::vec2 scale = glm::vec2(0.0);
};

struct VelocityComponent
{
    glm::vec2 velocity = glm::vec2(0, 0);
};

Prune::Engine::Engine()
{
    m_EngineName = "PruneEngine";
    m_EngineRunning = false;
    m_Borderless = false;
    m_Fullscreen = false;

    PRUNE_LOG_INFO("Engine set to not running");
}

Prune::Engine::~Engine()
{
}

void Prune::Engine::Down()
{
    SDL_DestroyRenderer(m_Renderer);
    PRUNE_LOG_INFO("Destroyed the renderer");
    SDL_DestroyWindow(m_Window);
    PRUNE_LOG_INFO("Destroyed the window");
    SDL_Quit();
    PRUNE_LOG_INFO("SDL Quit");
}

void Prune::Engine::Run()
{
    entt::registry registry;
    entt::entity entity = m_Registry.create();

    m_Registry.emplace<TransformComponent>(entity, glm::vec2(10, 10), glm::vec2(1, 1));
    m_Registry.emplace<VelocityComponent>(entity, glm::vec2(50, 50));

    while (m_EngineRunning)
    {
        CaptureInputEvents();
        Update();
        Render();
    }
}

void Prune::Engine::Up()
{
    Engine::SDLInit();
    Engine::SDLCreateWindow();
    Engine::SDLCreateRenderer();

    m_EngineRunning = true;

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

void Prune::Engine::Update()
{
    auto view = m_Registry.view<TransformComponent, VelocityComponent>();

    for (auto entity : view) {
        auto& transform = view.get<TransformComponent>(entity);
        auto& velocity = view.get<VelocityComponent>(entity);

        PRUNE_LOG_INFO("Transform set to x: {0}, y: {1}", transform.transform.x, transform.transform.y);

        transform.transform.x += 10;

        PRUNE_LOG_INFO("Transform set to x: {0}, y: {1}", transform.transform.x, transform.transform.y);
    }
}

void Prune::Engine::Render()
{
    SDL_SetRenderDrawColor(
        m_Renderer,
        m_WindowBackgroundR,
        m_WindowBackgroundG,
        m_WindowBackgroundB,
        m_WindowBackgroundA
    );
    SDL_RenderClear(m_Renderer);



    SDL_RenderPresent(m_Renderer);
}

void Prune::Engine::SDLCreateRenderer()
{
    m_Renderer = SDL_CreateRenderer(
        m_Window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
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
