#include "../Component/TransformComponent.h"
#include "../Component/VelocityComponent.h"
#include "MovementSystem.h"
#include "../Log/Log.h"

void MovementSystem::Update(entt::registry& registry)
{
    auto view = registry.view<TransformComponent, VelocityComponent>();

    for (auto entity : view) {
        auto& transform = view.get<TransformComponent>(entity);
        auto& velocity = view.get<VelocityComponent>(entity);

        PRUNE_LOG_INFO("Transform set to x: {0}, y: {1}", transform.transform.x, transform.transform.y);

        transform.transform.x += 10;

        PRUNE_LOG_INFO("Transform set to x: {0}, y: {1}", transform.transform.x, transform.transform.y);
    }
};
