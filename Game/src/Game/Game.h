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

        void CaptureEvents();
        void CreateEntities();
        void AddSpritesToLibrary();
        void RunSystems(double deltaTime);
        void RenderEntities();
        void RenderBackground();

    private:
        SDL_Renderer* m_Renderer = nullptr;
        entt::registry m_Registry;
        SpriteLibrary m_SpriteLibrary;
    };
}
