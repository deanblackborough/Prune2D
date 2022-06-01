#include <entt.hpp>
#include <SDL.h>

namespace Prune 
{
    /**
     * Iterate all the entities entities with transform and boxcollider2d components and render the 
     * box collider
     */
    class BoxColliderRenderSystem
    {
    public:
        BoxColliderRenderSystem() = default;
        ~BoxColliderRenderSystem() = default;

        void Render(
            entt::registry& registry, 
            SDL_Renderer* renderer,
            bool showBoxColliders2D
        );
    };
}
