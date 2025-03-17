#pragma once
#include <SFML/Graphics.hpp>

namespace constants
{
	constexpr unsigned int WINDOW_WIDTH = 512u;
	constexpr unsigned int WINDOW_HEIGHT = 960u;
	constexpr sf::Vector2u WINDOW_SIZE{ WINDOW_WIDTH, WINDOW_HEIGHT };
	constexpr char* WINDOW_TITLE = "tetris-cpp";
}
