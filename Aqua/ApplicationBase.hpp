#pragma region Include
#include <fstream>
#include <deque>
#pragma endregion

class ApplicationBase {
public:
	ApplicationBase() = default;
	~ApplicationBase() = default;

	bool ConfigBuilder() {
		std::ifstream(this->GetAppBasePath() + "config.txt");
			

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
	/*About developer*/
private:
	std::string app_base_path = "src/bin/data/";
	std::string app_items_path = "src/bin/data/item/";
	std::string app__path = "src/bin/data/";
	/*About developer*/
private:
	std::string dev_discord	{ "@watan.1337" };
	std::string dev_github	{ "@watan104" };
	std::string dev_github_url	{ "https://github.com/watan104/" };
	/*About developer*/
};