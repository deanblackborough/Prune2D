#pragma once

#include <entt.hpp>
#include "../../../Event/Event.h"

namespace Prune
{
    /**
     * The collision event fired by the collision system, includes a reference to the registry and 
     * the two entities what collided. The Health system picks up the events and deals with them accordingly
     */
    class CollisionEvent : public Event
    {
    public:
        entt::entity a;
        entt::entity b;
        entt::registry& registry;

        CollisionEvent(entt::registry& registry, entt::entity a, entt::entity b) 
            : registry(registry), a(a), b(b) 
        {
        }

    private:

    };
}