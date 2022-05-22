#include "Game.h"
#include "../Component/TransformComponent.h"
#include "../Component/VelocityComponent.h"
#include "../Component/SpriteComponent.h"
#include "../Component/AnimatedSpriteComponent.h"
#include "../System/AnimatedSpriteSystem.h"
#include "../System/MovementSystem.h"
#include "../System/SpriteRenderSystem.h"

Prune::Game::Game()
{
    m_SpriteLibrary = SpriteLibrary();
}

void Prune::Game::InitECS()
{
    entt::registry m_Registry;
}

void Prune::Game::SetRenderer(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
}

void Prune::Game::CaptureEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        /*switch (event.type)
        {
        }*/
    }
}

void Prune::Game::CreateEntities()
{
    // Default
    entt::entity entity1 = m_Registry.create();
    m_Registry.emplace<TransformComponent>(entity1, glm::vec2(10, 10), glm::vec2(1, 1));
    m_Registry.emplace<VelocityComponent>(entity1, glm::vec2(0, 0));
    m_Registry.emplace<SpriteComponent>(entity1, "character-idle", 64, 64);
    m_Registry.emplace<AnimatedSpriteComponent>(entity1, 1, 4, 6);

    entt::entity entity2 = m_Registry.create();
    m_Registry.emplace<TransformComponent>(entity2, glm::vec2(10, 100), glm::vec2(1, 1));
    m_Registry.emplace<VelocityComponent>(entity2, glm::vec2(0, 0));
    m_Registry.emplace<SpriteComponent>(entity2, "character-attack", 128, 64, 0, 0, 128, 64);
    m_Registry.emplace<AnimatedSpriteComponent>(entity2, 1, 4, 6);
}

void Prune::Game::AddSpritesToLibrary()
{
    m_SpriteLibrary.SetRenderer(m_Renderer);
    m_SpriteLibrary.AddSprite("character-idle", "assets\\sprites\\character-idle.png");
    m_SpriteLibrary.AddSprite("character-attack", "assets\\sprites\\character-attack.png");
}

void Prune::Game::RunSystems(double delta)
{
    MovementSystem movementSystem = MovementSystem();
    movementSystem.Update(m_Registry, delta);

    AnimatedSpriteSystem animatedSpriteSystem = AnimatedSpriteSystem();
    animatedSpriteSystem.Update(m_Registry);
}

void Prune::Game::RenderEntities()
{
    SpriteRenderSystem spriteRenderSystem = SpriteRenderSystem();
    spriteRenderSystem.Update(m_Registry, m_Renderer, m_SpriteLibrary);
}

void Prune::Game::RenderBackground()
{
    SDL_SetRenderDrawColor(m_Renderer, 80, 50, 185, 255);
    SDL_RenderClear(m_Renderer);
}
