#pragma once

#include <entt.hpp>

namespace Prune
{
    /**
     * Iterate through all entities with sprite and animated sprite components and calculate 
     * the source rectangle to use from the sprite based on the desired frame speed
     */
    class AnimatedSpriteSystem
    {
    public:
        AnimatedSpriteSystem() = default;
        ~AnimatedSpriteSystem() = default;

        void Update(entt::registry& registry);
    };
}
