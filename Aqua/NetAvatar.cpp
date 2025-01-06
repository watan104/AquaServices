#include "NetAvatar.hpp"

NetAvatar::NetAvatar(ENetPeer* peer) : 
	m_peer(peer),
	PeerPacket{ peer }
{
	if (!m_peer) return;
	m_peer->data = new uint32_t(m_peer->connectID);
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

void NetAvatar::SetNetID(const std::uint32_t& nid)
{
	m_net_id = nid;
}
std::uint32_t NetAvatar::GetNetID() const
{
	return m_net_id;
}

std::string NetAvatar::GetRequestedName()
{
	return m_requested_name;
}

std::string NetAvatar::GetTankIDName()
{
	return m_tank_id_name;
}

std::string NetAvatar::GetTankIDPass()
{
	return m_tank_id_pass;
}

std::string NetAvatar::GetRawName()
{
	return m_raw_name;
}

std::string NetAvatar::GetDisplayName()
{
	return m_display_name;
}

std::string NetAvatar::GetIP()
{
	return m_ip;
}

std::string NetAvatar::GetWorld()
{
	return m_world;
}

std::string NetAvatar::GetPlatformID()
{
	return m_platform_id;
}

void NetAvatar::SetGameVersion(const float& version)
{
	m_game_version = version;
}

float NetAvatar::GetGameVersion()
{
	return m_game_version;
}

std::string NetAvatar::GetCountry()
{
	return m_country;
}

std::string NetAvatar::GetMAC()
{
	return m_mac;
}

std::string NetAvatar::GetRID()
{
	return m_rid;
}

std::string NetAvatar::GetDoorID()
{
	return m_door_id;
}

std::string NetAvatar::GetLogonMode()
{
	return m_door_id;
}

