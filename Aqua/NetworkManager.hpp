#include <enet/enet.h>
#include <fmt/core.h>
#include <fmt/color.h>
#include "ApplicationConfig.hpp"
#include <memory>
#include <deque>
#include "AvatarPool.hpp"

class NetworkManager {
public:
    NetworkManager(std::string m_name, uint16_t m_port, size_t m_max_peers) : m_name(m_name), m_port(m_port), m_max_peers(m_max_peers), m_host(nullptr) {}

    ~NetworkManager() {
        if (m_host) enet_host_destroy(m_host);
    }
    bool Start();
    void Poll(std::deque<std::shared_ptr<NetworkManager>> m_network);

	std::shared_ptr<AvatarPool> GetAvatarPool() { return m_avatar; }

private:
    std::string m_name;
    uint16_t m_port;
    size_t m_max_peers;
    ENetHost* m_host;
private:
    ApplicationConfig g_app_config;
	std::shared_ptr<AvatarPool> m_avatar;
};