#include <string>
#include <array>
#include <functional>
#include <algorithm>
#include "AvatarRoles.hpp"
#include "CommandContext.hpp"

class Command {
public:
    static constexpr size_t m_max_aliases = 10;

    Command(std::string name, std::initializer_list<std::string> aliases, std::string description, eAvatarRole role, std::function<void(const CommandContext&)> handler) : m_name(std::move(name)),
        m_description(std::move(description)),
        m_role(role),
        m_handler(std::move(handler)) {
        size_t count = min(aliases.size(), m_max_aliases);
        std::copy_n(aliases.begin(), count, m_alias_array.begin());
        m_alias_count = count;
    }

    ~Command() = default;

    [[nodiscard]] const std::string& Name() const { return m_name; }
    void SetName(std::string new_name) { m_name = std::move(new_name); }

    [[nodiscard]] std::array<std::string, m_max_aliases> Aliases() const {
        std::array<std::string, m_max_aliases> result;
        std::copy_n(m_alias_array.begin(), m_alias_count, result.begin());
        return result;
    }
    void SetAliases(std::initializer_list<std::string> new_aliases) {
        size_t count = min(new_aliases.size(), m_max_aliases);
        std::copy_n(new_aliases.begin(), count, m_alias_array.begin());
        m_alias_count = count;
    }

    [[nodiscard]] const std::string& Description() const { return m_description; }
    void SetDescription(std::string new_description) { m_description = std::move(new_description); }

    [[nodiscard]] eAvatarRole Role() const { return m_role; }
    void SetRole(eAvatarRole new_role) { m_role = new_role; }

    [[nodiscard]] const std::function<void(const CommandContext&)>& Handler() const { return m_handler; }
    void SetHandler(std::function<void(const CommandContext&)> new_handler) { m_handler = std::move(new_handler); }

private:
    std::string m_name;
    std::array<std::string, m_max_aliases> m_alias_array{};
    size_t m_alias_count = 0;
    std::string m_description;
    eAvatarRole m_role;
    std::function<void(const CommandContext&)> m_handler;
};
