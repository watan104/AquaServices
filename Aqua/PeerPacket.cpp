#include "PeerPacket.hpp"

ENetPeer* PeerPacket::GetPeer()
{
    return m_peer;
}

void PeerPacket::Send(TankUpdatePacket tank_packet, uintmax_t data_size)
{
    if (not this->GetPeer()) return;
    ENetPacket* packet = enet_packet_create(nullptr, data_size, ENET_PACKET_FLAG_RELIABLE);
    if (not packet) return;
    std::copy(reinterpret_cast<uint8_t*>(&tank_packet), reinterpret_cast<uint8_t*>(&tank_packet) + data_size, packet->data);
    if (enet_peer_send(m_peer, 0, packet) not_eq 0) enet_packet_destroy(packet);
}

void PeerPacket::Send(TankUpdatePacket* tank_packet, uintmax_t data_size)
{
    if (not this->GetPeer()) return;
    GameUpdatePacket* update_packet = reinterpret_cast<GameUpdatePacket*>(&tank_packet->m_data);
    ENetPacket* packet = enet_packet_create(nullptr, data_size, ENET_PACKET_FLAG_RELIABLE);
    if (not packet or not update_packet) return;
    
    std::copy(reinterpret_cast<uint8_t*>(&tank_packet->m_type), reinterpret_cast<uint8_t*>(&tank_packet->m_type) + 4, packet->data);
    std::copy(reinterpret_cast<uint8_t*>(update_packet), reinterpret_cast<uint8_t*>(update_packet) + sizeof(GameUpdatePacket) + update_packet->m_data_size, packet->data + 4);

    if (enet_peer_send(m_peer, 0, packet) not_eq 0) enet_packet_destroy(packet);
}

void PeerPacket::Send(int32_t type, const void* data, uintmax_t data_size)
{
    if (not this->GetPeer()) return;
    ENetPacket* packet = enet_packet_create(nullptr, 5 + data_size, ENET_PACKET_FLAG_RELIABLE);
    if (not packet) return;
    std::copy(reinterpret_cast<uint8_t*>(&type), reinterpret_cast<uint8_t*>(&type) + 4, packet->data);
    if (data) std::copy(reinterpret_cast<const uint8_t*>(data), reinterpret_cast<const uint8_t*>(data) + data_size, packet->data + 4);
    packet->data[data_size + 4] = 0;
    if (enet_peer_send(m_peer, 0, packet) not_eq 0) enet_packet_destroy(packet);
}

void PeerPacket::Variant(const variantlist_t& var, int32_t delay, int32_t net_id)
{
    std::size_t alloc = 1;
    for (const auto& var_obj : var.GetObjects())
        alloc += var_obj.GetMemAlloc() + 1; 
    const uint8_t* buffer = var.Serialize().get();
    GameUpdatePacket* update_packet = new GameUpdatePacket[sizeof(GameUpdatePacket) + alloc];
    update_packet->m_type = NET_GAME_PACKET_CALL_FUNCTION;
    update_packet->m_net_id = net_id;
    update_packet->m_flags |= NET_GAME_PACKET_FLAGS_EXTENDED;
    update_packet->m_delay = delay;
    update_packet->m_data_size = static_cast<uint32_t>(alloc);
    std::copy_n(buffer, alloc, update_packet->m_data);
    this->Send(NET_MESSAGE_GAME_PACKET, update_packet, sizeof(GameUpdatePacket) + update_packet->m_data_size);
    delete[] update_packet;
}
