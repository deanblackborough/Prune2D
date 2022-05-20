#include "RenderSystem.h"
#include "../Component/TransformComponent.h"
#include "../Component/SpriteComponent.h"

void Prune::RenderSystem::Update(entt::registry& registry, SDL_Renderer* renderer)
{
    auto view = registry.view<TransformComponent, SpriteComponent>();

    for (auto entity : view) {
        TransformComponent& transformComponent = view.get<TransformComponent>(entity);
        SpriteComponent& spriteComponent = view.get<SpriteComponent>(entity);

        SDL_Rect destinationRectangle = {
            static_cast<int>(transformComponent.position.x),
            static_cast<int>(transformComponent.position.y),
            static_cast<int>(spriteComponent.width * transformComponent.scale.x),
            static_cast<int>(spriteComponent.height * transformComponent.scale.y)
        };

        SDL_Surface* surface = IMG_Load("assets\\sprites\\yellow-animated-star.png");
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        SDL_RenderCopyEx(
            renderer,
            texture,
            &spriteComponent.sourceRect,
            &destinationRectangle,
            transformComponent.rotation,
            NULL,
            SDL_FLIP_NONE
        );
    }
};
