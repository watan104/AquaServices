#include "LoginHandler.hpp"

LoginHandler::LoginHandler(std::string_view text)
{
	if (text.starts_with("requestedName")) this->GuestLogon();
	if (text.starts_with("tankIDName")) this->GrowIDLogon();
	if (text.starts_with("protocol|") and text.find("ltoken|")) this->TokenLogon();
	return;
}
