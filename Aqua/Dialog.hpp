#include <string>
#include <fmt/core.h>

enum class ElementSize {
	EXTRA_SMALL,
	SMALL,
	MEDIUM,
	LARGE,
	BIG
};

enum class ElementDirections {
	LEFT,
	RIGHT,
	CENTER
};

class Dialog {
public:
	Dialog()  =	default;
	~Dialog() = default;

	std::string Build() const;

	std::string GetSizeString(ElementSize size);
	std::string GetDirectionString(ElementDirections direction);
	void		Destroy();

	Dialog		*SetDefaultColor(char c);
	Dialog		*AddSpacer(const ElementSize& size);
	Dialog		*AddLabelWithIcon(const ElementSize& size, const std::string& text, const ElementDirections& direction,const int& icon);

private:
	std::string		m_menu	{ "" };
};