#include "ButtonManager.h"

void ButtonManager::update(float dt)
{
	static bool wasMouseButtonPressed = false;
	bool mouseButtonDown = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if(!wasMouseButtonPressed)
			mouseButtonDown = true;
		wasMouseButtonPressed = true;
	}
	else
		wasMouseButtonPressed = false;
	

	sf::Vector2i mousePosInt = sf::Mouse::getPosition(m_window);
	sf::Vector2f mousePos = { (float)mousePosInt.x, (float)mousePosInt.y };

	for (auto& buttonPtr : m_buttons)
	{
		Button& button = *buttonPtr;
		if (isMouseOverButton(button, mousePos))
		{
			if (!button.MouseOver)
			{
				button.onMouseEnter();
				button.MouseOver = true;
			}
			if (mouseButtonDown)
			{
				button.onMouseClick();
			}
		}
		else
		{
			if (button.MouseOver)
			{
				button.onMouseExit();
				button.MouseOver = false;
			}
		}
	}
}

void ButtonManager::render(sf::RenderWindow& window)
{
	for (auto& button : m_buttons)
	{
		button->draw(window);
	}
}

Button& ButtonManager::addButton(std::function<void()> onClick, sf::String text, sf::Vector2f position, sf::Vector2f size,
	unsigned int textSize, sf::Color textColor, sf::Color backgroundColor)
{
	auto buttonPtr = std::make_unique<Button>(onClick);
	Button& button = *buttonPtr;
	m_buttons.push_back(std::move(buttonPtr));
	auto& buttonShape = button.getShape();
	buttonShape.setSize(size);
	buttonShape.setOrigin(size / 2.0f);
	buttonShape.setPosition(position);
	buttonShape.setFillColor(backgroundColor);
	buttonShape.setOutlineColor(sf::Color::White);
	buttonShape.setOutlineThickness(5);
	auto& buttonText = button.getText();
	buttonText.setCharacterSize(textSize);
	buttonText.setString(text);
	buttonText.setOrigin(buttonText.getLocalBounds().size / 2.0f);
	buttonText.setPosition(buttonShape.getPosition());

	return button;
}

void ButtonManager::removeButton(Button& button)
{
	auto it = std::remove_if(m_buttons.begin(), m_buttons.end(), [&button](std::unique_ptr<Button>& b) { return b.get() == &button; });
	if (it != m_buttons.end())
	{
		m_buttons.erase(it, m_buttons.end());
	}
}

bool ButtonManager::isMouseOverButton(Button& button, sf::Vector2f mousePos)
{
	return button.getShape().getGlobalBounds().contains(mousePos);
}
