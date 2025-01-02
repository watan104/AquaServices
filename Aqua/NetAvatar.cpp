#include "NetAvatar.hpp"

NetAvatar::NetAvatar(ENetPeer* peer) : m_peer(peer) 
{
	if (!m_peer) return;
	m_peer->data = new uint32_t;
	std::memcpy(m_peer->data, &m_peer->connectID, sizeof(uint32_t));
	m_ip.reserve(16);
	enet_address_get_host_ip(&m_peer->address, m_ip.data(), 16);
}

NetAvatar::~NetAvatar()
{
	if (!m_peer) return;
	delete m_peer->data;
	m_peer->data = nullptr;
	m_peer = nullptr;
}
