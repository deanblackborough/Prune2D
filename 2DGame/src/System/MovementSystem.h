#include <entt.hpp>

class MovementSystem
{
public:
    MovementSystem() = default;
    ~MovementSystem() = default;
    
    void Update(entt::registry& registry);
};