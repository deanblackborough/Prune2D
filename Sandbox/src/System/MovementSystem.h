#include <entt.hpp>

namespace Prune 
{
    /** 
     * Iterate all the entities entities with transform and velocity components and calculate 
     * the new position based on the velocity
     */
    class MovementSystem
    {
    public:
        MovementSystem() = default;
        ~MovementSystem() = default;

        void Update(entt::registry& registry, double delta);
    };
}
