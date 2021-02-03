#pragma once

#include <Events/PacketEvent.h>

struct World;
struct UpdateEvent;
struct TransportService;
struct RequestActorValuesState;
struct RequestActorValueChanges;
struct RequestActorMaxValueChanges;
struct RequestHealthChangeBroadcast;

struct ActorService
{
    ActorService(entt::dispatcher& aDispatcher, World& aWorld) noexcept;
    ~ActorService() noexcept;

    TP_NOCOPYMOVE(ActorService);

  private:
    World& m_world;

    void OnActorValuesState(const PacketEvent<RequestActorValuesState>& acMessage) const noexcept;
    void OnActorValueChanges(const PacketEvent<RequestActorValueChanges>& acMessage) const noexcept;
    void OnActorMaxValueChanges(const PacketEvent<RequestActorMaxValueChanges>& acMessage) const noexcept;
    void OnHealthChangeBroadcast(const PacketEvent<RequestHealthChangeBroadcast>& acMessage) const noexcept;

    entt::scoped_connection m_updateHealthConnection;
    entt::scoped_connection m_updateMaxValueConnection;
    entt::scoped_connection m_updateDeltaHealthConnection;
};
