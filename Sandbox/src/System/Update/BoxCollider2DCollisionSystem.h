#include <entt.hpp>
#include <glm.hpp>

namespace Prune 
{
    /** 
     * Detect collisions between box colliders, keeping things simple initially, using AABB collision, 
     * will add support for rotated box colliders down the line
     */
    class BoxCollider2DCollisionSystem
    {
    public:
        BoxCollider2DCollisionSystem() = default;
        ~BoxCollider2DCollisionSystem() = default;

        void Update(entt::registry& registry);

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
