#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:
	Button(std::function<void()> onClick);
	inline sf::Text& getText() { return m_text; }
	inline sf::RectangleShape& getShape() { return m_shape; }
	void draw(sf::RenderWindow& window);	
	void onMouseEnter();
	void onMouseExit();
	void onMouseClick();
	bool MouseOver = false;
private:
	sf::RectangleShape m_shape;
	sf::Text m_text;
	std::function<void()> m_onClick;
	sf::Color m_defaultColor;
};