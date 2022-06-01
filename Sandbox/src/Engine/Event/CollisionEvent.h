#pragma once

#include <entt.hpp>
#include "../../../Event/Event.h"

namespace Prune
{
    class CollisionEvent : public Event
    {
    public:
        entt::entity a;
        entt::entity b;
        entt::registry& registry;

        CollisionEvent(entt::registry& registry, entt::entity a, entt::entity b) : registry(registry), a(a), b(b) {}

    private:

    };
}