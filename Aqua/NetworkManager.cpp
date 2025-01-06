#include "NetworkManager.hpp"
#include "NetAvatar.hpp"
#include "Packet.hpp"
#include "LoginHandler.hpp"

bool NetworkManager::Start()
{
    if (enet_initialize() != 0) return false;
    ENetAddress m_address{
        .host = ENET_HOST_ANY,
	    .port = m_port
    };
    m_host = enet_host_create(&m_address, m_max_peers, 2, 0, 0);
    if (!m_host)
    {
		fmt::print("Failed to create {} server -> {} port\n", m_name, m_port);
        return false;
    }
    fmt::print(fmt::fg(fmt::color::black) | fmt::bg(fmt::color::lime) | fmt::emphasis::bold, "\"NetworkManager Class\" started {} server -> {} port\n", m_name, m_port);
    return true;
}

void NetworkManager::Poll(std::deque<std::shared_ptr<NetworkManager>> m_network)
{
    for (auto& m_server : m_network) {

        if (!m_host) return;
        ENetEvent m_event{};
        while (enet_host_service(m_host, &m_event, 0) > 0) {
            switch (m_event.type) {
                case ENET_EVENT_TYPE_NONE:
                {
                    break;
                }
                case ENET_EVENT_TYPE_CONNECT:
                {
                    std::shared_ptr<NetAvatar> m_avatar = { m_server->GetAvatarPool()->Add(m_event.peer) };
                    fmt::print(fmt::fg(fmt::color::black) | fmt::bg(fmt::color::aqua) | fmt::emphasis::bold, "[{}] Client connected with {} ID\n", this->m_port, m_event.peer->connectID);
                    m_avatar->Send({ NET_MESSAGE_SERVER_HELLO }, sizeof(TankUpdatePacket));
                    break;
                }
                case ENET_EVENT_TYPE_DISCONNECT:
                {
                    fmt::print(fmt::fg(fmt::color::black) | fmt::bg(fmt::color::aqua) | fmt::emphasis::bold, "[{}] Client disconnected with {} ID\n", this->m_port, m_event.peer->connectID);
				    if (not m_event.peer->data) break;
                    std::uint32_t connect_id{};
                    std::copy(reinterpret_cast<std::uint8_t*>(m_event.peer->data), reinterpret_cast<std::uint8_t*>(m_event.peer->data) + sizeof(std::uint32_t), reinterpret_cast<std::uint8_t*>(&connect_id));
                    delete[] m_event.peer->data;
                    m_event.peer->data = NULL;          
                    if (not m_server->GetAvatarPool()->Get(connect_id)) return;
				    m_server->GetAvatarPool()->Remove(connect_id);
                    break;
                }
                case ENET_EVENT_TYPE_RECEIVE:
                {
                    std::shared_ptr<NetAvatar> m_avatar = { m_server->GetAvatarPool()->Get(m_event.peer->connectID) };
                    switch (*((int32_t*)m_event.packet->data)) {
                    case NET_MESSAGE_GENERIC_TEXT: {
                        std::fill_n(m_event.packet->data + m_event.packet->dataLength - 1, 1, 0);
                        std::string get_text(reinterpret_cast<const char*>(m_event.packet->data) + 4);
						LoginHandler get_login{ m_avatar, get_text };
                        if (get_text.starts_with("action|refresh_item_data")) {

                        }
                        if (get_text.starts_with("action|enter_game")) {

						}
                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
            }
        }
        enet_host_service(m_server->GetHost(), nullptr, 0);
    }
}

