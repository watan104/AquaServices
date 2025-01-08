#include "Dialog.hpp"

std::string Dialog::Build() const
{
    return m_menu;
}

std::string Dialog::GetSizeString(ElementSize size)
{
	switch (size)
	{
	case ElementSize::EXTRA_SMALL:
		return "extra_small";
	case ElementSize::SMALL:
		return "small";
	case ElementSize::MEDIUM:
		return "medium";
	case ElementSize::LARGE:
		return "large";
	case ElementSize::BIG:
		return "big";
	}
	return "small";
}

std::string Dialog::GetDirectionString(ElementDirections direction)
{
	switch (direction)
	{
	case ElementDirections::LEFT:
		return "left";
	case ElementDirections::RIGHT:
		return "right";
	case ElementDirections::CENTER:
		return "center";
	}
	return "left";
}

void Dialog::Destroy()
{
	m_menu.clear();
}

Dialog* Dialog::SetDefaultColor(char c)
{
	m_menu.append(fmt::format("set_default_color|`{}\n", c));
	return this;
}

Dialog* Dialog::AddSpacer(const ElementSize& size)
{
	m_menu.append(fmt::format("add_spacer|{}\n", GetSizeString(size)));
	return this;
}

Dialog* Dialog::AddLabelWithIcon(const ElementSize& size, const std::string& text, const ElementDirections& direction, const int& icon)
{
	m_menu.append(fmt::format("add_label_with_icon|{}|{}|{}|{}\n", GetSizeString(size), text, GetDirectionString(direction), icon));
	return this;
}