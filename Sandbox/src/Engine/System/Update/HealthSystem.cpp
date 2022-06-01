#include "HealthSystem.h"
#include "../../../Log/Log.h"

void Prune::HealthSystem::SubscribeToEvents(std::unique_ptr<EventBus>& eventBus)
{
    eventBus->SubscribeToEvent<CollisionEvent>(this, &HealthSystem::OnCollision);
}

void Prune::HealthSystem::OnCollision(CollisionEvent& event)
{
    event.registry.destroy(event.a);
    event.registry.destroy(event.b);

    PRUNE_LOG_INFO("Called the OnCollision callback method and killed the entities");
}
