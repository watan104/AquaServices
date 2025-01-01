#include <memory>
#include <unordered_map>
#include <enet/enet.h>
#include "NetAvatar.hpp"
#include <mutex>

class AvatarPool {
public:
	AvatarPool() = default;
	~AvatarPool() = default;

	std::shared_ptr<NetAvatar> Add(ENetPeer* peer);
	_NODISCARD std::unordered_map<uint32_t, std::shared_ptr<NetAvatar>> const& GetAvatars() const;
	_NODISCARD std::size_t Count() const;
	void Clear();
private:
    mutable std::mutex m_mutex;
    std::unordered_map<uint32_t, std::shared_ptr<NetAvatar>> m_avatars;
};