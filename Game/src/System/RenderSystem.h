#include <entt.hpp>
#include <SDL.h>
#include <SDL_image.h>

namespace Prune 
{
    class RenderSystem
    {
    public:
        RenderSystem() = default;
        ~RenderSystem() = default;

        void Update(entt::registry& registry, SDL_Renderer* renderer);
    };
}