#pragma once

#include <entt.hpp>
#include "../../../Event/EventBus.h"
#include "../../Event/CollisionEvent.h"

namespace Prune
{
    class DamageSystem
    {
    public:
        DamageSystem() = default;
        ~DamageSystem() = default;

        void SubscribeToEvents(std::unique_ptr<EventBus>& eventBus);

        void OnCollision(CollisionEvent& event);

    private:
    };
}
