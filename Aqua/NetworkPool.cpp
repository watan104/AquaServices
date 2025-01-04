#include "NetworkPool.hpp"

void NetworkPool::Add(std::string m_name, uint16_t m_port, size_t m_max_peers)
{
    if (auto m_server = std::make_shared<NetworkManager>(m_name, m_port, m_max_peers); m_server->Start()) {
        m_servers.push_back(std::move(m_server));
    }
}

void NetworkPool::Poll()
{
    for (const auto& server : m_servers) {
        server->Poll(m_servers);
    }
}
