#include "Game.h"
#include "../Component/TransformComponent.h"
#include "../Component/VelocityComponent.h"
#include "../System/MovementSystem.h"
#include "../System/RenderSystem.h"

void Prune::Game::SetRegistry(entt::registry& registry)
{
    
}

void Prune::Game::SetRenderer(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
}

void Prune::Game::SetDeltaTime(double deltaTime)
{
    m_DeltaTime = deltaTime;
}

void Prune::Game::Entities(entt::registry& registry)
{
    entt::entity entity = registry.create();

    registry.emplace<TransformComponent>(entity, glm::vec2(10, 60), glm::vec2(1, 1));
    registry.emplace<VelocityComponent>(entity, glm::vec2(200, 0));
}

void Prune::Game::Systems(entt::registry& registry, double delta)
{
    MovementSystem movementSystem = MovementSystem();
    movementSystem.Update(registry, delta);
}

void Prune::Game::Render(entt::registry& registry)
{
    RenderSystem renderSystem = RenderSystem();
    renderSystem.Update(registry, m_Renderer);
}

void Prune::Game::RenderBackground()
{
    SDL_SetRenderDrawColor(m_Renderer, 80, 50, 185,255);
    SDL_RenderClear(m_Renderer);
}
