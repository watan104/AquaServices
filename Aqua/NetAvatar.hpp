#ifndef NETAVATAR_HPP
#define NETAVATAR_HPP

#include <enet/enet.h>
#include <string>
#include <algorithm>
#include <memory>

class NetAvatar {
public:
	explicit NetAvatar(ENetPeer* peer);
	~NetAvatar();
private:
	ENetPeer*		m_peer;

	std::string		m_requested_name	{ "" };
	std::string		m_tank_id_name		{ "" };
	std::string		m_tank_id_pass		{ "" };
	std::string		m_raw_name			{ "" };
	std::string		m_display_name		{ "" };
	std::string		m_ip				{ "" };
};

#endif // NETAVATAR_HPP