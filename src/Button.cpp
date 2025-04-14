#include "Button.h"
#include "const.h"

Button::Button(std::function<void()> onClick) : m_onClick(onClick), m_text(CONST::FONT)
{
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
	window.draw(m_text);
}

void Button::onMouseEnter()
{
	m_defaultColor = m_shape.getFillColor();
	m_shape.setFillColor(sf::Color(
		static_cast<int>(m_defaultColor.r * 1.5f),
		static_cast<int>(m_defaultColor.g * 1.5f),
		static_cast<int>(m_defaultColor.b * 1.5f),
		m_defaultColor.a
	));
}

void Button::onMouseExit()
{
	m_shape.setFillColor(m_defaultColor);
}

void Button::onMouseClick()
{
	m_onClick();
}
