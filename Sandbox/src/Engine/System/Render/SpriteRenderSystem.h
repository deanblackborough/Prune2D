#include <entt.hpp>
#include <SDL.h>
#include <SDL_image.h>
#include "../../../Library/SpriteLibrary.h"

namespace Prune 
{
    /**
     * Iterate all the entities entities with transform and sprite components and render the 
     * sprite textures
     */
    class SpriteRenderSystem
    {
    public:
        SpriteRenderSystem() = default;
        ~SpriteRenderSystem() = default;

        void Render(
            entt::registry& registry, 
            SDL_Renderer* renderer,
            SpriteLibrary& spriteLibrary
        );
    };
}
