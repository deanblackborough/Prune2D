#include "BoxCollider2DCollisionSystem.h"
#include "../../Component/TransformComponent.h"
#include "../../Component/BoxCollider2DComponent.h"
#include "../../../Log/Log.h"

void Prune::BoxCollider2DCollisionSystem::Update(entt::registry& registry)
{
    auto outer_view = registry.view<TransformComponent, BoxCollider2DComponent>();

    for (auto outer_entity : outer_view) {
        TransformComponent& transformComponentOuter = outer_view.get<TransformComponent>(outer_entity);
        BoxCollider2DComponent& boxCollider2DComponentOuter = outer_view.get<BoxCollider2DComponent>(outer_entity);

        auto inner_view = registry.view<TransformComponent, BoxCollider2DComponent>();

        for (auto inner_entity : inner_view) {
            TransformComponent& transformComponentInner = inner_view.get<TransformComponent>(inner_entity);
            BoxCollider2DComponent& boxCollider2DComponentInner = inner_view.get<BoxCollider2DComponent>(inner_entity);

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
                    PRUNE_LOG_INFO("There has been a collision!!!");
                }
            }
        }
    }
};

bool Prune::BoxCollider2DCollisionSystem::checkForCollision(
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
