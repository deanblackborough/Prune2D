#include <entt.hpp>
#include <SDL.h>
#include <SDL_image.h>
#include "../Library/SpriteLibrary.h"

namespace Prune 
{
    class SpriteRenderSystem
    {
    public:
        SpriteRenderSystem() = default;
        ~SpriteRenderSystem() = default;

        void Update(
            entt::registry& registry, 
            SDL_Renderer* renderer,
            SpriteLibrary& spriteLibrary
        );
    };
}
