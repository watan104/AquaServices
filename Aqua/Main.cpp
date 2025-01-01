#pragma region Include
#include <enet/enet.h>
#include <iostream>
#include <cstdlib>
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
	SetConsoleTitleW(L"Growtopia Server");
	if (enet_initialize() != 0) return EXIT_FAILURE;
	NetworkPool g_pool;
	ApplicationBase* g_app = new ApplicationBase();
	g_pool.Add("EPS", 17777, 1024);
	g_pool.Add("APS", 17091, 1024);
	g_pool.Add("GrowtopiaOS", 16999, 1024);
	while (true) {
		g_pool.Poll();
	}
	
}