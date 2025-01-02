#include <memory>
#include <deque>
#include <string>
#include "NetAvatar.hpp"

class NetworkPool;

/*Credit RebillionX - GrowtopiaServer*/
struct CommandContext {
    std::shared_ptr<NetAvatar> m_player;
    //std::shared_ptr<Server> m_server;
    NetworkPool* m_servers;
    std::deque<std::string> m_arguments;
};
/*Credit RebillionX - GrowtopiaServer*/