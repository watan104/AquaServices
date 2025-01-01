#pragma region Include
#include <enet/enet.h>
#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#pragma endregion

#pragma region Modules
#include "NetworkPool.hpp"
#include "ApplicationBase.hpp"
#pragma endregion

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Winmm.lib")

auto main() -> int {
	ApplicationBase* app = new ApplicationBase();
	return 0;
}