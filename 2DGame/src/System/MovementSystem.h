#include <entt.hpp>

namespace Prune 
{
    class MovementSystem
    {
    public:
        MovementSystem() = default;
        ~MovementSystem() = default;

        void Update(entt::registry& registry, double delta);
    };
}