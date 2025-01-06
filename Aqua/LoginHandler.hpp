#include <string>
#include "ApplicationBase.hpp"
#include "NetAvatar.hpp"
#include "TextScanner.hpp"

class LoginHandler {
public:
	/*nedret bir daha string view kullan ananý sikerim*/
	LoginHandler(std::shared_ptr<NetAvatar> m_avatar, std::string text);
	~LoginHandler() = default;

	void GuestLogon(std::shared_ptr<NetAvatar> m_avatar,std::string text);
	void GrowIDLogon(std::shared_ptr<NetAvatar> m_avatar, std::string_view text);
	void TokenLogon(std::shared_ptr<NetAvatar> m_avatar, std::string_view text);
};