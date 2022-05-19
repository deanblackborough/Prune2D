#include "RenderSystem.h"
#include "../Component/TransformComponent.h"
#include "../Component/VelocityComponent.h"
#include "../Log/Log.h"

void Prune::RenderSystem::Update(entt::registry& registry, SDL_Renderer* renderer)
{
    auto view = registry.view<TransformComponent>();

    for (auto entity : view) {
        TransformComponent& transformComponent = view.get<TransformComponent>(entity);

        SDL_SetRenderDrawColor(renderer, 220, 20, 45, 255); 
        SDL_Rect rect(
            static_cast<int>(transformComponent.transform.x),
            static_cast<int>(transformComponent.transform.y),
            32, 
            32
        );
        SDL_RenderFillRect(renderer, &rect);
    }
};
