#include "CollisionSystem.h"
#include "../../Component/TransformComponent.h"
#include "../../Component/BoxColliderComponent.h"
#include "../../Event/CollisionEvent.h"
#include "../../../Log/Log.h"

void Prune::CollisionSystem::Update(entt::registry& registry, std::unique_ptr<EventBus>& eventBus)
{
    auto outer_view = registry.view<TransformComponent, BoxColliderComponent>();

    for (auto outer_entity : outer_view) {
        TransformComponent& transformComponentOuter = outer_view.get<TransformComponent>(outer_entity);
        BoxColliderComponent& boxCollider2DComponentOuter = outer_view.get<BoxColliderComponent>(outer_entity);

        auto inner_view = registry.view<TransformComponent, BoxColliderComponent>();

        for (auto inner_entity : inner_view) {
            TransformComponent& transformComponentInner = inner_view.get<TransformComponent>(inner_entity);
            BoxColliderComponent& boxCollider2DComponentInner = inner_view.get<BoxColliderComponent>(inner_entity);

            if (inner_entity == outer_entity)
            {
                continue;
            }
            else
            {
                bool collision = checkForCollision(
                    static_cast<int>(transformComponentOuter.translation.x + boxCollider2DComponentOuter.offset.x),
                    static_cast<int>(transformComponentOuter.translation.y + boxCollider2DComponentOuter.offset.y),
                    static_cast<int>(boxCollider2DComponentOuter.size.x * transformComponentOuter.scale.x),
                    static_cast<int>(boxCollider2DComponentOuter.size.y * transformComponentOuter.scale.y),
                    static_cast<int>(transformComponentInner.translation.x + boxCollider2DComponentInner.offset.x),
                    static_cast<int>(transformComponentInner.translation.y + boxCollider2DComponentInner.offset.y),
                    static_cast<int>(boxCollider2DComponentInner.size.x * transformComponentInner.scale.x),
                    static_cast<int>(boxCollider2DComponentInner.size.y * transformComponentInner.scale.y)
                );

                if (collision)
                {
                    eventBus->EmitEvent<CollisionEvent>(registry, inner_entity, outer_entity);
                    PRUNE_LOG_INFO("There has been a collision!!!");
                }
            }
        }
    }
};

bool Prune::CollisionSystem::checkForCollision(
    int outerPositionX,
    int outerPositionY,
    int outerWidth,
    int outerHeight,
    int innerPositionX,
    int innerPositionY,
    int innerWidth,
    int innerHeight
)
{
    return (
        outerPositionX < innerPositionX + innerWidth &&
        outerPositionX + outerWidth > innerPositionX &&
        outerPositionY < innerPositionY + innerHeight &&
        outerPositionY + outerHeight > innerPositionY
    );
};
