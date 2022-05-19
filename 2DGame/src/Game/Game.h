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

        void Entities(entt::registry& registry);
        void Systems(entt::registry& registry, double delta);
        void Render(entt::registry& registry, SDL_Renderer* renderer);
        void RenderBackground(SDL_Renderer* renderer);
    };
}
