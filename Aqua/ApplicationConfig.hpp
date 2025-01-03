#ifndef APPLICATION_CONFIG_HPP
#define APPLICATION_CONFIG_HPP

#include <cstdint>
#include <string>

struct ApplicationConfig {
	std::string		server_name{ "" };
	std::uint16_t	main_port{ 0 };
	std::uint16_t	sub_port{ 0 };
	std::uint16_t	last_port{ 0 };
};

#endif // APPLICATION_CONFIG_HPP