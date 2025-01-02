#include "AvatarPool.hpp"

std::shared_ptr<NetAvatar> AvatarPool::Add(ENetPeer* peer)
{
    if (m_avatars.find(peer->connectID) == m_avatars.end()) {
        auto avatar = std::make_shared<NetAvatar>(peer);
        m_avatars[peer->connectID] = avatar;
        return avatar;
    }
}

std::unordered_map<uint32_t, std::shared_ptr<NetAvatar>> const& AvatarPool::GetAvatars() const
{
	return m_avatars;
}

std::size_t AvatarPool::Count() const
{
    return m_avatars.size();
}

void AvatarPool::Clear()
{
	m_avatars.clear();
}
