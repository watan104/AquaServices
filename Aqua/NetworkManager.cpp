#include "NetworkManager.hpp"

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

void NetworkManager::Poll()
{
    fmt::detail::color_type color;
    if (m_name == "EPS") {
        color = fmt::color::crimson;
    }
    else if (m_name == "APS") {
        color = fmt::color::aqua;
    }
    else if (m_name == "GrowtopiaOS") {
        color = fmt::color::light_yellow;
    }
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
            fmt::print(fmt::fg(fmt::color::black) | fmt::bg(color) | fmt::emphasis::bold, "[{}] Client connected with {} ID\n", m_name, m_event.peer->connectID);
            break;
        }
        case ENET_EVENT_TYPE_DISCONNECT:
        {
            fmt::print(fmt::fg(fmt::color::black) | fmt::bg(color) | fmt::emphasis::bold, "[{}] Client disconnected with {} ID\n", m_name, m_event.peer->connectID);
            break;
        }
        case ENET_EVENT_TYPE_RECEIVE:
        {
            fmt::print(fmt::fg(fmt::color::black) | fmt::bg(color) | fmt::emphasis::bold, "[{}] Client received packet with {} ID\n", m_name, m_event.peer->connectID);
            break;
        }
        }
    }
}
