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
