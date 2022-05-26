#include "AnimatedSpriteSystem.h"
#include "../Component/SpriteComponent.h"
#include "../Component/AnimatedSpriteComponent.h"

void Prune::AnimatedSpriteSystem::Update(entt::registry& registry)
{
    auto view = registry.view<SpriteComponent, AnimatedSpriteComponent>();

    for (auto entity : view) {
        SpriteComponent& spriteComponent = view.get<SpriteComponent>(entity);
        AnimatedSpriteComponent& animatedSpriteComponent = view.get<AnimatedSpriteComponent>(entity);

        int frame = (
            (
                (SDL_GetTicks() - animatedSpriteComponent.startTime) * 
                animatedSpriteComponent.frameSpeed / 1000
            ) % animatedSpriteComponent.animationFrames
        );
 
        spriteComponent.sourceRect.x = (frame * spriteComponent.sourceRectWidth);
    }
}
