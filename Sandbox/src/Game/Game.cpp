#include "Game.h"
#include "../Component/AnimatedSpriteComponent.h"
#include "../Component/BoxCollider2D.h"
#include "../Component/SpriteComponent.h"
#include "../Component/TransformComponent.h"
#include "../Component/VelocityComponent.h"
#include "../System/Update/AnimatedSpriteSystem.h"
#include "../System/Update/MovementSystem.h"
#include "../System/Render/SpriteRenderSystem.h"

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

void Prune::Game::CreateEntities()
{
    entt::entity plane_grey = m_Registry.create();
    m_Registry.emplace<TransformComponent>(plane_grey, glm::vec2(10, 10), glm::vec2(1, 1));
    m_Registry.emplace<VelocityComponent>(plane_grey, glm::vec2(100, 0));
    m_Registry.emplace<SpriteComponent>(plane_grey, "plane-grey-right", 32, 32, 0, 0, 128, 128);
    m_Registry.emplace<BoxCollider2D>(plane_grey, glm::vec2(32, 32));

    entt::entity plane_green = m_Registry.create();
    m_Registry.emplace<TransformComponent>(plane_green, glm::vec2((800-10-64), 10), glm::vec2(1, 1));
    m_Registry.emplace<VelocityComponent>(plane_green, glm::vec2(-100, 0));
    m_Registry.emplace<SpriteComponent>(plane_green, "plane-green-left", 32, 32, 0, 0, 128, 128);
    m_Registry.emplace<BoxCollider2D>(plane_green, glm::vec2(32, 32));
}

void Prune::Game::AddSpritesToLibrary()
{
    m_SpriteLibrary.SetRenderer(m_Renderer);
    m_SpriteLibrary.AddSprite("plane-grey-right", "assets\\sprites\\plane-grey-right.png");
    m_SpriteLibrary.AddSprite("plane-green-left", "assets\\sprites\\plane-green-left.png");
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
    spriteRenderSystem.Render(m_Registry, m_Renderer, m_SpriteLibrary);
}

void Prune::Game::RenderBackground()
{
    SDL_SetRenderDrawColor(m_Renderer, 80, 50, 185, 255);
    SDL_RenderClear(m_Renderer);
}
