#include "LoginHandler.hpp"

LoginHandler::LoginHandler(std::shared_ptr<NetAvatar> m_avatar, std::string text)
{
	if (text.starts_with("requestedName")) this->GuestLogon(m_avatar, text);
	if (text.starts_with("tankIDName")) this->GrowIDLogon(m_avatar, text);
	if (text.starts_with("protocol|") and text.find("ltoken|")) this->TokenLogon(m_avatar, text);
	return;
}
