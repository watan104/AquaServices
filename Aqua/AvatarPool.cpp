#include "AvatarPool.hpp"

std::shared_ptr<NetAvatar> AvatarPool::Add(ENetPeer* peer)
{
    auto [it, inserted] = m_avatars.try_emplace(peer->connectID, nullptr);
    if (inserted) it->second = std::make_shared<NetAvatar>(peer);   
    return it->second;
}

void AvatarPool::Remove(uint32_t connect_id)
{
    m_avatars.erase(connect_id);
}

std::shared_ptr<NetAvatar> AvatarPool::Get(uint32_t connect_id)
{
    auto it = m_avatars.find(connect_id);
    return (it != m_avatars.end()) ? it->second : nullptr;
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
