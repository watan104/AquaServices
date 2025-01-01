#pragma once
#include <string>
#include <unordered_map>

enum eAvatarRole {
    PLAYER_ROLE_DEFAULT,
    PLAYER_ROLE_MODERATOR,
    PLAYER_ROLE_ADMINISTRATOR
};

static std::unordered_map<int, char> role_color = {
    { PLAYER_ROLE_DEFAULT, 'w' },
    { PLAYER_ROLE_MODERATOR, '#' },
    { PLAYER_ROLE_ADMINISTRATOR, '6' }
};

static std::unordered_map<int, std::string> role_name = {
	{ PLAYER_ROLE_DEFAULT, "Player" },
	{ PLAYER_ROLE_MODERATOR, "`#Moderator" },
	{ PLAYER_ROLE_ADMINISTRATOR, "`6Admin" }
};

static std::unordered_map<int, std::string> role_chat = {
	{ PLAYER_ROLE_DEFAULT, "w" },
	{ PLAYER_ROLE_MODERATOR, "^" },
	{ PLAYER_ROLE_ADMINISTRATOR, "5" }
};