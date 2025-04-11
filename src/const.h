#pragma once
#include <SFML/Graphics.hpp>
#include <array>

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


	constexpr float CLEAR_ROWS_ANIM_STEP_DELAY = 0.1f;



	constexpr float PIECE_MOVE_PERIOD = 1.0f / 15.0f; // seconds / cell
	constexpr float PIECE_FALL_PERIOD = 1.0f; // seconds / cell
	constexpr float PIECE_FALL_PERIOD_FAST = 1.0f / 20.0f; // // seconds / cell

	//level
	constexpr std::array<float, 30> LEVEL_FALL_PERIODS = // seconds / cell
	{
		0.800f,
		0.716f,
		0.633f,
		0.550f,
		0.466f,
		0.383f,
		0.300f,
		0.216f,
		0.133f,
		0.100f,
		0.083f,
		0.083f,
		0.083f,
		0.066f,
		0.066f,
		0.066f,
		0.050f,
		0.050f,
		0.050f,
		0.033f,
		0.033f,
		0.033f,
		0.033f,
		0.033f,
		0.033f,
		0.033f,
		0.033f,
		0.033f,
		0.033f,
		0.0167f
	};

	constexpr std::array<int, 5> LEVEL_POINTS_PER_ROW =
	{
		0,
		40,
		100,
		300,
		1200
	};


}
