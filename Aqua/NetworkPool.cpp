#include "NetworkPool.hpp"

void NetworkPool::Add(std::string m_name, uint16_t m_port, size_t m_max_peers)
{
    auto m_server = std::make_shared<NetworkManager>(m_name, m_port, m_max_peers);
    if (m_server->Start()) {
        m_servers.push_back(m_server);
    }
}

void NetworkPool::Poll()
{
    for (auto& m_server : m_servers) {
<<<<<<< HEAD
        m_server->Poll(m_servers);
=======
        m_server->Poll();
>>>>>>> e5098cd4116c508ca18db06fbb7f5088aee4ad42
    }
}
