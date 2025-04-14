#pragma once
#include "Button.h"
#include <vector>
#include <memory>

class ButtonManager
{
public:
	ButtonManager(sf::RenderWindow& window) : m_window(window) {}
	void update(float dt);
	void render(sf::RenderWindow& window);
	Button& addButton(std::function<void()> onClick, sf::String text, sf::Vector2f position, sf::Vector2f size, 
					  unsigned int textSize, sf::Color textColor, sf::Color backgroundColor);
	void removeButton(Button& button);
private:
	std::vector<std::unique_ptr<Button>> m_buttons;
	sf::RenderWindow& m_window;
private:
	bool isMouseOverButton(Button& button, sf::Vector2f mousePos);
};