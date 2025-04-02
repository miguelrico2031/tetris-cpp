#include <SFML/Graphics.hpp>
#include <string>
#include "CONST.h"
#include "Logger.h"
#include "Game.h"

int main()
{
	//Init clock and window
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(CONST::WINDOW_SIZE), CONST::WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
	Game game;
	game.start();
	
	//window.setFramerateLimit(60);

	while (window.isOpen())
	{
		//Handle events
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else
			{
				game.handleEvents(event);
			}
		}

		//Update game
		float deltaTimeSeconds = clock.restart().asSeconds();
		game.update(deltaTimeSeconds);

		//render
		game.render(window);

	}

	return 0;
}

//void handleEvents(sf::RenderWindow& window)
//{
//	while (const std::optional event = window.pollEvent())
//	{
//		if (event->is<sf::Event::Closed>())
//		{
//			window.close();
//		}
//
//
//		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
//		{
//			Logger::log("key down: " + std::to_string((int)keyPressed->code));
//		}
//		else if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
//		{
//			Logger::log("key up: " + std::to_string((int)keyPressed->code));
//		}
//		else if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
//		{
//			sf::Vector2i pos = mouseMoved->position;
//		}
//		else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
//		{
//			Logger::log("mouse button down: " + std::to_string((int)mouseButtonPressed->button));
//		}
//		else if (const auto* mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>())
//		{
//			Logger::log("mouse button up: " + std::to_string((int)mouseButtonReleased->button));
//		}
//		else if (const auto* joystickPressed = event->getIf < sf::Event::JoystickButtonPressed>())
//		{
//			Logger::log("joystick button down: " + std::to_string((int)joystickPressed->button));
//		}
//		else if (const auto* joystickReleased = event->getIf < sf::Event::JoystickButtonReleased>())
//		{
//			Logger::log("joystick button up: " + std::to_string((int)joystickReleased->button));
//		}
//		else if (const auto* joystickMoved = event->getIf<sf::Event::JoystickMoved>())
//		{
//			if (joystickMoved->axis == sf::Joystick::Axis::X)
//			{
//				Logger::log("joystick moved X: " + std::to_string(joystickMoved->position));
//			}
//			else if (joystickMoved->axis == sf::Joystick::Axis::Y)
//			{
//				Logger::log("joystick moved Y: " + std::to_string(joystickMoved->position));
//			}
//		}
//	}
//}

