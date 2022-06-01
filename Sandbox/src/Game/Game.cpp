#include "Game.h"
#include "../Engine/Component/AnimatedSpriteComponent.h"
#include "../Engine/Component/BoxColliderComponent.h"
#include "../Engine/Component/SpriteComponent.h"
#include "../Engine/Component/TransformComponent.h"
#include "../Engine/Component/VelocityComponent.h"
#include "../Engine/System/Update/AnimatedSpriteSystem.h"
#include "../Engine/System/Update/CollisionSystem.h"
#include "../Engine/System/Update/HealthSystem.h"
#include "../Engine/System/Update/MovementSystem.h"
#include "../Engine/System/Render/BoxColliderRenderSystem.h"
#include "../Engine/System/Render/SpriteRenderSystem.h"

Prune::Game::Game()
{
    InitECS();

    m_SpriteLibrary = SpriteLibrary();
    m_EventBus = std::make_unique<EventBus>();
    m_IsRunning = true;
}

void Prune::Game::Run()
{
    // This is effectively the level/menu being loaded, later
    // on, work out how we have going to handle that, for now, 
    // OK to go straight to the game as that is all we have
    {
        AddSpritesToLibrary();
        CreateEntities();
    }

    Uint32 frameEndTime = 0;

    while (m_IsRunning)
    {
        Uint32 frameStartTime = SDL_GetTicks();

        CaptureInputEvents();

        double deltaTime = (frameStartTime - frameEndTime) / 1000.f;

        m_EventBus->Reset();

        RunSystems(deltaTime);

        Render();

        frameEndTime = frameStartTime;
    }
}

void Prune::Game::Render()
{
    RenderBackground();
    RenderEntities();

    SDL_RenderPresent(m_Renderer);
}

void Prune::Game::CaptureInputEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_IsRunning = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                m_IsRunning = false;
                break;
            case SDLK_d:
                m_ShowBoxColliders2D = !m_ShowBoxColliders2D;
                break;
            }

            break;
        }
    }
}

void Prune::Game::InitECS()
{
    entt::registry m_Registry;
}

void Prune::Game::SetRenderer(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
}

void Prune::Game::CreateEntities()
{
    entt::entity plane_grey = m_Registry.create();
    m_Registry.emplace<TransformComponent>(plane_grey, glm::vec2(10, (300-16)), glm::vec2(1, 1));
    m_Registry.emplace<VelocityComponent>(plane_grey, glm::vec2(100, 0));
    m_Registry.emplace<SpriteComponent>(plane_grey, "plane-grey-right", 32, 32, 0, 0, 128, 128);
    m_Registry.emplace<BoxColliderComponent>(plane_grey, glm::vec2(32, 32));

    entt::entity plane_green = m_Registry.create();
    m_Registry.emplace<TransformComponent>(plane_green, glm::vec2((800-10-32), (300 - 16)), glm::vec2(1, 1));
    m_Registry.emplace<VelocityComponent>(plane_green, glm::vec2(-100, 0));
    m_Registry.emplace<SpriteComponent>(plane_green, "plane-green-left", 32, 32, 0, 0, 128, 128);
    m_Registry.emplace<BoxColliderComponent>(plane_green, glm::vec2(32, 32));
}

void Prune::Game::AddSpritesToLibrary()
{
    m_SpriteLibrary.SetRenderer(m_Renderer);
    m_SpriteLibrary.AddSprite("plane-grey-right", "assets\\sprites\\plane-grey-right.png");
    m_SpriteLibrary.AddSprite("plane-green-left", "assets\\sprites\\plane-green-left.png");
}

void Prune::Game::RunSystems(double delta)
{
    HealthSystem damageSystem = HealthSystem();
    damageSystem.SubscribeToEvents(m_EventBus);

    MovementSystem movementSystem = MovementSystem();
    movementSystem.Update(m_Registry, delta);

    AnimatedSpriteSystem animatedSpriteSystem = AnimatedSpriteSystem();
    animatedSpriteSystem.Update(m_Registry);

    CollisionSystem boxCollider2DCollisionSystem = CollisionSystem();
    boxCollider2DCollisionSystem.Update(m_Registry, m_EventBus);
}

void Prune::Game::RenderEntities()
{
    SpriteRenderSystem spriteRenderSystem = SpriteRenderSystem();
    spriteRenderSystem.Render(m_Registry, m_Renderer, m_SpriteLibrary);

    BoxColliderRenderSystem boxCollider2DRenderSystem = BoxColliderRenderSystem();
    boxCollider2DRenderSystem.Render(m_Registry, m_Renderer, m_ShowBoxColliders2D);
}

void Prune::Game::RenderBackground()
{
    SDL_SetRenderDrawColor(m_Renderer, 80, 50, 185, 255);
    SDL_RenderClear(m_Renderer);
}