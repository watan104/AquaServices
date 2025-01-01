#pragma region Include
#include <deque>
#include "TextScanner.hpp"
#pragma endregion

class ApplicationBase {
public:
	ApplicationBase() {

	}
	~ApplicationBase() = default;

	bool ConfigBuilder() {
		TextScanner t("config.txt");
		if (not t.IsLoaded()) return false;
		/*to-do*/
		
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
	const char*		database_name		{ nullptr };
	const char*		database_url		{ nullptr };
	const char*		database_pass		{ nullptr };
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