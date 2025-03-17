#include <SFML/Graphics.hpp>
#include "const.h"

int main()
{
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(constants::WINDOW_SIZE), constants::WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
	sf::CircleShape shape(100.0f);
	shape.setFillColor({ 200, 50, 50 });
	shape.setPosition({ 156.0f, 156.0f });

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}
