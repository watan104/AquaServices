#ifndef NETAVATAR_HPP
#define NETAVATAR_HPP
#include <enet/enet.h>
#include <string>
#include <algorithm>
#include <memory>
#include "PeerPacket.hpp"

class NetAvatar : public PeerPacket {
public:
	explicit NetAvatar(ENetPeer* peer);
	~NetAvatar();

	_NODISCARD ENetPeer* GetAvatarPeer() const { return m_peer; };

	void Disconnect(const enet_uint32& time_data) { enet_peer_disconnect_later(this->GetAvatarPeer(), time_data); };

	void SetUserID(const std::uint32_t& uid);
	_NODISCARD std::uint32_t GetUserID();
	void SetConnectID(const std::uint32_t& cid);
	_NODISCARD std::uint32_t GetConnectID() const;
	void SetNetID(const std::uint32_t& nid);
	_NODISCARD std::uint32_t GetNetID() const;

	_NODISCARD std::string GetRequestedName();
	_NODISCARD std::string GetTankIDName();
	_NODISCARD std::string GetTankIDPass();
	_NODISCARD std::string GetRawName();
	_NODISCARD std::string GetDisplayName();
	_NODISCARD std::string GetIP();
	_NODISCARD std::string GetWorld();
	_NODISCARD std::string GetPlatformID();
	_NODISCARD float GetGameVersion();
	_NODISCARD std::string GetCountry();
	_NODISCARD std::string GetMAC();
	_NODISCARD std::string GetRID();
	_NODISCARD std::string GetDoorID();
	_NODISCARD std::string GetLogonMode();

private:
	ENetPeer		*m_peer				{ NULL };
	std::uint32_t	m_user_id			{ NULL };
	std::uint32_t	m_connect_id		{ NULL };
	std::uint32_t	m_net_id			{ NULL };

	std::string		m_requested_name	{ "" };
	std::string		m_tank_id_name		{ "" };
	std::string		m_tank_id_pass		{ "" };
	std::string		m_raw_name			{ "" };
	std::string		m_display_name		{ "" };
	std::string		m_ip				{ "" };
	std::string 	m_world				{ "EXIT" };

	std::string		m_platform_id		{ "" };
	float			m_game_version		{ NULL };
	std::string		m_country			{ "us" }; //Default country is United States
	std::string		m_mac				{ "" };
	std::string		m_rid				{ "" };
	std::string		m_door_id			{ "" };
	std::string		m_logon_mode		{ "" };
};

#endif // NETAVATAR_HPP