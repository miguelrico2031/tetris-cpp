#pragma once
#include <SFML/Graphics.hpp>

namespace CONST
{
	constexpr size_t WINDOW_WIDTH = 512u;
	constexpr size_t WINDOW_HEIGHT = 960u;
	constexpr sf::Vector2u WINDOW_SIZE{ WINDOW_WIDTH, WINDOW_HEIGHT };
	constexpr char* WINDOW_TITLE = "tetris-cpp";

	constexpr sf::Color CLEAR_COLOR = { 0, 0, 0 };


	constexpr size_t BLOCK_SIZE = 30;
	constexpr sf::Vector2f BLOCK_SIZE_V = { BLOCK_SIZE, BLOCK_SIZE };


	constexpr size_t BOARD_WIDTH = 10;
	constexpr size_t BOARD_HEIGHT = 20;
	constexpr size_t BOARD_SIZE = BOARD_WIDTH * BOARD_HEIGHT;

	constexpr sf::Vector2f BOARD_POSITION =
	{
		((int)WINDOW_WIDTH / 2.0f) - ((int)BOARD_WIDTH * (int)BLOCK_SIZE / 2.0f), 
		((int)WINDOW_HEIGHT / 2.0f) - ((int)BOARD_HEIGHT * (int)BLOCK_SIZE / 2.0f)
	};



	constexpr sf::Color BOARD_BACKGROUND_GRID_COLOR = { 60, 60, 60 };
	constexpr float BOARD_BACKGROUND_GRID_THICKNESS = 2.0f;


	constexpr float PIECE_MOVE_SPEED = 15.0f;
	constexpr float PIECE_FALL_SPEED = 1.0f;
	constexpr float PIECE_FALL_SPEED_FAST = 20.0f;

}
