<<<<<<< HEAD
#ifndef NETAVATAR_HPP
#define NETAVATAR_HPP

=======
>>>>>>> e5098cd4116c508ca18db06fbb7f5088aee4ad42
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