#include <string>
#include "ApplicationBase.hpp"

class LoginHandler {
public:
	LoginHandler(std::string_view text);
	~LoginHandler() = default;

	void GuestLogon();
	void GrowIDLogon();
	void TokenLogon();
};