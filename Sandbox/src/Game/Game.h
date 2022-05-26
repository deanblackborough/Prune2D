#pragma once

#include <SDL.h>
#include <entt.hpp>
#include "../Library/SpriteLibrary.h"

namespace Prune
{
    class Game
    {
    public:
        Game();
        ~Game() = default;

        void InitECS();
        void SetRenderer(SDL_Renderer* renderer);

        void CreateEntities();
        void AddSpritesToLibrary();
        void RunSystems(double deltaTime);
        void RenderEntities();
        void RenderBackground();
        void SetShowBoxColliders2D(bool showBoxColliders2D);

    private:
        SDL_Renderer* m_Renderer = nullptr;
        entt::registry m_Registry;
        SpriteLibrary m_SpriteLibrary;

        bool m_ShowBoxColliders2D;
    };
}
