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

        void Render();
        void Run();
        void SetRenderer(SDL_Renderer* renderer);

    private:
        SDL_Renderer* m_Renderer = nullptr;
        entt::registry m_Registry;
        SpriteLibrary m_SpriteLibrary;

        bool m_ShowBoxColliders2D = false;
        bool m_IsRunning = false;
        
        void InitECS();
        void RenderEntities();
        void RenderBackground();
        
        void CreateEntities();
        void AddSpritesToLibrary();
        void RunSystems(double deltaTime);
        void CaptureInputEvents();
    };
}
