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

void NetAvatar::SetUserID(const std::uint32_t& uid)
{
	m_user_id = uid;
}

std::uint32_t NetAvatar::GetUserID()
{
	return m_user_id;
}

void NetAvatar::SetConnectID(const std::uint32_t& cid)
{
	m_connect_id = cid;
}

std::uint32_t NetAvatar::GetConnectID() const
{
	return m_connect_id;
}
