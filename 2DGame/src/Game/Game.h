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

        void SetRegistry(entt::registry& registry);
        void SetRenderer(SDL_Renderer* renderer);
        void SetDeltaTime(double deltaTime);

        void Entities(entt::registry& registry);
        void Systems(entt::registry& registry, double deltaTime);
        void Render(entt::registry& registry);
        void RenderBackground();

    private:
        SDL_Renderer* m_Renderer;
        entt::registry m_Registry;
        double m_DeltaTime;
    };
}
