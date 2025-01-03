<<<<<<< HEAD
#ifndef NETWORK_POOL_HPP
#define NETWORK_POOL_HPP

=======
>>>>>>> e5098cd4116c508ca18db06fbb7f5088aee4ad42
#include "NetworkManager.hpp"
#include <enet/enet.h>
#include <deque>
#include <memory>

class NetworkPool {
public:
    void Add(std::string m_name, uint16_t m_port, size_t m_max_peers);
    void Poll();
private:
<<<<<<< HEAD
    std::deque<std::shared_ptr<NetworkManager>> m_servers;
};

#endif // NETWORK_POOL_HPP
=======
	std::deque<std::shared_ptr<NetworkManager>> m_servers;
};
>>>>>>> e5098cd4116c508ca18db06fbb7f5088aee4ad42
