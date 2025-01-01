#include <enet/enet.h>
#include <fmt/core.h>
#include <fmt/color.h>

class NetworkManager {
public:
    NetworkManager(std::string m_name, uint16_t m_port, size_t m_max_peers) : m_name(m_name), m_port(m_port), m_max_peers(m_max_peers), m_host(nullptr) {}

    ~NetworkManager() {
        if (m_host) enet_host_destroy(m_host);
    }

    bool Start();

    void Poll();

private:
    std::string m_name;
    uint16_t m_port;
    size_t m_max_peers;
    ENetHost* m_host;
};