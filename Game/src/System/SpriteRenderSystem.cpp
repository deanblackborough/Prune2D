#include "SpriteRenderSystem.h"
#include "../Component/TransformComponent.h"
#include "../Component/SpriteComponent.h"
#include "../Log/Log.h"

void Prune::SpriteRenderSystem::Update(
    entt::registry& registry, 
    SDL_Renderer* renderer,
    SpriteLibrary& spriteLibrary
)
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

        SDL_Texture* texture = spriteLibrary.GetSpriteTexture(spriteComponent.spriteId);
        if (texture != nullptr)
        {

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
        else
        {
            PRUNE_LOG_ERROR("Unable to fetch texture from SpriteLibrary for key '{0}'", spriteComponent.spriteId);
        }
    }
};
