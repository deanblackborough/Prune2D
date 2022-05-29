#include "Game.h"
#include "../Engine/Component/AnimatedSpriteComponent.h"
#include "../Engine/Component/BoxCollider2DComponent.h"
#include "../Engine/Component/SpriteComponent.h"
#include "../Engine/Component/TransformComponent.h"
#include "../Engine/Component/VelocityComponent.h"
#include "../Engine/System/Update/AnimatedSpriteSystem.h"
#include "../Engine/System/Update/BoxCollider2DCollisionSystem.h"
#include "../Engine/System/Update/MovementSystem.h"
#include "../Engine/System/Render/BoxCollider2DRenderSystem.h"
#include "../Engine/System/Render/SpriteRenderSystem.h"

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
    m_Registry.emplace<TransformComponent>(plane_grey, glm::vec2(10, (300-16)), glm::vec2(1, 1));
    m_Registry.emplace<VelocityComponent>(plane_grey, glm::vec2(100, 0));
    m_Registry.emplace<SpriteComponent>(plane_grey, "plane-grey-right", 32, 32, 0, 0, 128, 128);
    m_Registry.emplace<BoxCollider2DComponent>(plane_grey, glm::vec2(32, 32));

    entt::entity plane_green = m_Registry.create();
    m_Registry.emplace<TransformComponent>(plane_green, glm::vec2((800-10-32), (300 - 16)), glm::vec2(1, 1));
    m_Registry.emplace<VelocityComponent>(plane_green, glm::vec2(-100, 0));
    m_Registry.emplace<SpriteComponent>(plane_green, "plane-green-left", 32, 32, 0, 0, 128, 128);
    m_Registry.emplace<BoxCollider2DComponent>(plane_green, glm::vec2(32, 32));
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

    BoxCollider2DCollisionSystem boxCollider2DCollisionSystem = BoxCollider2DCollisionSystem();
    boxCollider2DCollisionSystem.Update(m_Registry);
}

void Prune::Game::RenderEntities()
{
    SpriteRenderSystem spriteRenderSystem = SpriteRenderSystem();
    spriteRenderSystem.Render(m_Registry, m_Renderer, m_SpriteLibrary);

    BoxCollider2DRenderSystem boxCollider2DRenderSystem = BoxCollider2DRenderSystem();
    boxCollider2DRenderSystem.Render(m_Registry, m_Renderer, m_ShowBoxColliders2D);
}

void Prune::Game::RenderBackground()
{
    SDL_SetRenderDrawColor(m_Renderer, 80, 50, 185, 255);
    SDL_RenderClear(m_Renderer);
}

void Prune::Game::SetShowBoxColliders2D(bool showBoxColliders2D)
{
    m_ShowBoxColliders2D = showBoxColliders2D;
}
