#include "BoxColliderRenderSystem.h"
#include "../../Component/TransformComponent.h"
#include "../../Component/BoxColliderComponent.h"
#include "../../../Log/Log.h"

void Prune::BoxColliderRenderSystem::Render(
    entt::registry& registry, 
    SDL_Renderer* renderer,
    bool showBoxColliders2D
)
{
    if (showBoxColliders2D)
    {
        auto view = registry.view<TransformComponent, BoxColliderComponent>();

        for (auto entity : view) {
            TransformComponent& transformComponent = view.get<TransformComponent>(entity);
            BoxColliderComponent& boxCollider2DComponent = view.get<BoxColliderComponent>(entity);

            SDL_Rect boxCollider2DRect = {
                static_cast<int>(transformComponent.translation.x + boxCollider2DComponent.offset.x),
                static_cast<int>(transformComponent.translation.y + boxCollider2DComponent.offset.y),
                static_cast<int>(boxCollider2DComponent.size.x * transformComponent.scale.x),
                static_cast<int>(boxCollider2DComponent.size.y * transformComponent.scale.x)
            };
            SDL_SetRenderDrawColor(renderer, 255, 185, 0, 255);
            SDL_RenderDrawRect(renderer, &boxCollider2DRect);
        }
    }
};
