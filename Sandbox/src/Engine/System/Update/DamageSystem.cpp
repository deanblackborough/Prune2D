#include "DamageSystem.h"
#include "../../../Log/Log.h"

void Prune::DamageSystem::SubscribeToEvents(std::unique_ptr<EventBus>& eventBus)
{
    eventBus->SubscribeToEvent<CollisionEvent>(this, &DamageSystem::OnCollision);
}

void Prune::DamageSystem::OnCollision(CollisionEvent& event)
{
    event.registry.destroy(event.a);
    event.registry.destroy(event.b);

    PRUNE_LOG_INFO("Called the OnCollision callback method and killed the entities");
}
