#ifndef NETWORK_POOL_HPP
#define NETWORK_POOL_HPP

#include "NetworkManager.hpp"
#include <enet/enet.h>
#include <deque>
#include <memory>

class NetworkPool {
public:
    void Add(std::string m_name, uint16_t m_port, size_t m_max_peers);
    void Poll();
private:
    std::deque<std::shared_ptr<NetworkManager>> m_servers;
};

#endif // NETWORK_POOL_HPP

