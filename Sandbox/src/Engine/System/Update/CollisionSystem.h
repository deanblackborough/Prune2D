#include <entt.hpp>
#include <glm.hpp>
#include "../../../Event/EventBus.h"

namespace Prune 
{
    /** 
     * Detect collisions between box colliders, keeping things simple initially, using AABB collision, 
     * will add support for rotated box colliders down the line
     */
    class CollisionSystem
    {
    public:
        CollisionSystem() = default;
        ~CollisionSystem() = default;

        void Update(entt::registry& registry, std::unique_ptr<EventBus>& eventBus);

    private:
        bool checkForCollision(
            int outerPositionX,
            int outerPositionY,
            int outerWidth,
            int outerHeight,
            int innerPositionX,
            int innerPositionY,
            int innerWidth,
            int innerHeight
        );
    };
}
