#include <enet/enet.h>
#include <fmt/core.h>
#include <fmt/color.h>
<<<<<<< HEAD
#include "ApplicationConfig.hpp"
#include <memory>
#include <deque>
#include "AvatarPool.hpp"
=======
>>>>>>> e5098cd4116c508ca18db06fbb7f5088aee4ad42

class NetworkManager {
public:
    NetworkManager(std::string m_name, uint16_t m_port, size_t m_max_peers) : m_name(m_name), m_port(m_port), m_max_peers(m_max_peers), m_host(nullptr) {}

    ~NetworkManager() {
        if (m_host) enet_host_destroy(m_host);
    }
<<<<<<< HEAD
    bool Start();
    void Poll(std::deque<std::shared_ptr<NetworkManager>> m_network);

	std::shared_ptr<AvatarPool> GetAvatarPool() { return m_avatar; }
=======

    bool Start();

    void Poll();

>>>>>>> e5098cd4116c508ca18db06fbb7f5088aee4ad42
private:
    std::string m_name;
    uint16_t m_port;
    size_t m_max_peers;
    ENetHost* m_host;
<<<<<<< HEAD
private:
    ApplicationConfig g_app_config;
	std::shared_ptr<AvatarPool> m_avatar;
=======
>>>>>>> e5098cd4116c508ca18db06fbb7f5088aee4ad42
};