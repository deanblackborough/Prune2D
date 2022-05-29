#include <entt.hpp>
#include <SDL.h>

namespace Prune 
{
    /**
     * Iterate all the entities entities with transform and boxcollider2d components and render the 
     * box collider
     */
    class BoxCollider2DRenderSystem
    {
    public:
        BoxCollider2DRenderSystem() = default;
        ~BoxCollider2DRenderSystem() = default;

        void Render(
            entt::registry& registry, 
            SDL_Renderer* renderer,
            bool showBoxColliders2D
        );
    };
}
