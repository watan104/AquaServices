#include "LoginHandler.hpp"

inline void LoginHandler::GuestLogon(std::shared_ptr<NetAvatar> m_avatar, std::string text)
{
	if (m_avatar->GetPeer() == NULL) return;
	TextScanner t{};
	t.SetupFromMemoryAddress(text.c_str());
	m_avatar->GetPlatformID() = t.GetParmString("platformID", 1);
	m_avatar->SetGameVersion(t.GetParmFloat("gameVersion", 1));
	m_avatar->GetCountry() = t.GetParmString("country", 1);
	m_avatar->GetMAC() = t.GetParmString("mac", 1);
	m_avatar->GetRID() = t.GetParmString("rid", 1);
	m_avatar->GetDoorID() = t.GetParmString("doorID", 1);
	m_avatar->GetLogonMode() = t.GetParmString("lmode", 1);

}