#pragma region Include
#include <enet/enet.h>
#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#pragma endregion

#pragma region Modules
#include "NetworkPool.hpp"
#include "ApplicationBase.hpp"
<<<<<<< HEAD
#include "ApplicationConfig.hpp"
=======
>>>>>>> e5098cd4116c508ca18db06fbb7f5088aee4ad42
#pragma endregion

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Winmm.lib")

<<<<<<< HEAD
ApplicationConfig g_app_config;
=======
>>>>>>> e5098cd4116c508ca18db06fbb7f5088aee4ad42
auto main() -> int {
	ApplicationBase* app = new ApplicationBase();
	return 0;
}