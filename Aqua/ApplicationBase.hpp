#pragma region Include
#include <deque>
#include "TextScanner.hpp"
#pragma endregion

class ApplicationBase {
public:
	ApplicationBase() {
		SetConsoleTitleW(L"Aqua Project");
		if (enet_initialize() != 0) {
			fmt::print(fg(fmt::color::black) | bg(fmt::color::crimson), "\"ApplicationBase\" An error occurred while initializing ENet.\n");
		}
		NetworkPool g_pool;
		g_pool.Add("SERVER-ONE", 17777, 1024);
		g_pool.Add("SERVER-TWO", 17091, 1024);
		g_pool.Add("SERVER-THREE", 16999, 1024);
		while (true) {
			g_pool.Poll();
		}
	}
	~ApplicationBase() = default;

	bool ConfigBuilder() {
		TextScanner t("config.txt");
		if (not t.IsLoaded()) return false;
		this->server_name = t.GetParmString("server_name", 1);
		this->main_port = t.GetParmUInt("main_port", 1);
		this->sub_port = t.GetParmUInt("sub_port", 1);
		this->last_port = t.GetParmUInt("last_port", 1);
		this->database_name = t.GetParmString("database_name", 1).c_str();
		this->database_url = t.GetParmString("database_url", 1).c_str();
		this->database_pass = t.GetParmString("database_pass", 1).c_str();
		t.Kill();
		return true;
	}	
public:
	std::string GetAppBasePath() const {
		return app_base_path;
	}
	std::string GetAppItemsPath() const {
		return app_items_path;
	}
	std::string GetAppPath() const {
		return app__path;
	}
private:	
	std::string		server_name			{ NULL };
	std::uint16_t	main_port			{ NULL };
	std::uint16_t	sub_port			{ NULL };
	std::uint16_t	last_port			{ NULL };
private:
	std::string		database_name		{ NULL };
	std::string		database_url		{ NULL };
	std::string		database_pass		{ NULL };
private:
	std::string		app_base_path		{ "src/bin/data/" };
	std::string		app_items_path		{ "src/bin/data/item/" };
	std::string		app__path			{ "src/bin/data/" };
	/*About developer*/
private:
	std::string		dev_discord			{ "@watan.1337" };
	std::string		dev_github			{ "@watan104" };
	std::string		dev_github_url		{ "https://github.com/watan104/" };
	/*About developer*/
};