#include "Game.h"
#include "../Component/TransformComponent.h"
#include "../Component/VelocityComponent.h"
#include "../System/MovementSystem.h"
#include "../System/RenderSystem.h"

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

void Prune::Game::Render(entt::registry& registry, SDL_Renderer* renderer)
{
    RenderSystem renderSystem = RenderSystem();
    renderSystem.Update(registry, renderer);
}

void Prune::Game::RenderBackground(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 80, 50, 185,255);
    SDL_RenderClear(renderer);
}
