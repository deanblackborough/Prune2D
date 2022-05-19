#pragma once

#include <SDL.h>
#include <entt.hpp>


namespace Prune
{
    class Game
    {
    public:
        Game() = default;
        ~Game() = default;

        void InitECS();
        void SetRenderer(SDL_Renderer* renderer);

        void CaptureEvents();
        void CreateEntities();
        void RunSystems(double deltaTime);
        void RenderEntities();
        void RenderBackground();

    private:
        SDL_Renderer* m_Renderer = nullptr;
        entt::registry m_Registry;
    };
}
