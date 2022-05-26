#pragma once

#include <entt.hpp>

namespace Prune
{
    class AnimatedSpriteSystem
    {
    public:
        AnimatedSpriteSystem() = default;
        ~AnimatedSpriteSystem() = default;

        void Update(entt::registry& registry);
    };
}
