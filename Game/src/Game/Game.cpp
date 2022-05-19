#include "Game.h"
#include "../Component/TransformComponent.h"
#include "../Component/VelocityComponent.h"
#include "../System/MovementSystem.h"
#include "../System/RenderSystem.h"

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
    entt::entity entity = m_Registry.create();

    m_Registry.emplace<TransformComponent>(entity, glm::vec2(10, 60), glm::vec2(1, 1));
    m_Registry.emplace<VelocityComponent>(entity, glm::vec2(200, 0));
}

void Prune::Game::RunSystems(double delta)
{
    MovementSystem movementSystem = MovementSystem();
    movementSystem.Update(m_Registry, delta);
}

void Prune::Game::RenderEntities()
{
    RenderSystem renderSystem = RenderSystem();
    renderSystem.Update(m_Registry, m_Renderer);
}

void Prune::Game::RenderBackground()
{
    SDL_SetRenderDrawColor(m_Renderer, 80, 50, 185,255);
    SDL_RenderClear(m_Renderer);
}
