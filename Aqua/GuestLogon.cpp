#include "LoginHandler.hpp"

inline void LoginHandler::GuestLogon(std::shared_ptr<NetAvatar> m_avatar, std::string text)
{
	if (m_avatar->GetPeer() == NULL) return;
	TextScanner t{};
	t.SetupFromMemoryAddress(text.c_str());
	m_avatar->
}