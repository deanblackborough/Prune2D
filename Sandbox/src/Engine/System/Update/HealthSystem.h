#pragma once

#include <entt.hpp>
#include "../../../Event/EventBus.h"
#include "../../Event/CollisionEvent.h"

namespace Prune
{
    /**
     * Captures CollisionEvents and deals with them, for now, we simply delete the two entities that have collided, 
     * as the system expands we will deal with the actual 'health' of the entities once we have a health component
     */
    class HealthSystem
    {
    public:
        HealthSystem() = default;
        ~HealthSystem() = default;

        void SubscribeToEvents(std::unique_ptr<EventBus>& eventBus);

        void OnCollision(CollisionEvent& event);

    private:
    };
}
