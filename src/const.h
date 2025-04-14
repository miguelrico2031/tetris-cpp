#pragma once  
#include <SFML/Graphics.hpp>  
#include <array>  

namespace CONST
{
	constexpr size_t BLOCK_SIZE = 40;
	constexpr sf::Vector2f BLOCK_SIZE_V = { BLOCK_SIZE, BLOCK_SIZE };

	constexpr sf::Vector2f HOLD_PANEL_SIZE = { (int)BLOCK_SIZE * 5.0f, (int)BLOCK_SIZE * 5.0f };
	constexpr sf::Vector2f HOLD_PANEL_POSITION = { 50.0f, 50.0f };
	const sf::String HOLD_PANEL_TEXT = "Hold";

	constexpr size_t BOARD_WIDTH = 10;
	constexpr size_t BOARD_HEIGHT = 20;
	constexpr size_t BOARD_SIZE = BOARD_WIDTH * BOARD_HEIGHT;

	constexpr sf::Vector2f BOARD_POSITION =
	{
		HOLD_PANEL_POSITION.x + HOLD_PANEL_SIZE.x + 50.0f,
		HOLD_PANEL_POSITION.y
	};

	constexpr sf::Color BOARD_BACKGROUND_GRID_COLOR = { 60, 60, 60 };
	constexpr float BOARD_BACKGROUND_GRID_THICKNESS = 2.0f;

	constexpr sf::Vector2f SCORE_PANEL_SIZE = { (int)BLOCK_SIZE * 5.0f, (int)BLOCK_SIZE * 10.0f };
	constexpr sf::Vector2f SCORE_PANEL_POSITION =
	{
		HOLD_PANEL_POSITION.x,
		BOARD_POSITION.y + BOARD_HEIGHT * BLOCK_SIZE - SCORE_PANEL_SIZE.y
	};
	const sf::String SCORE_PANEL_TEXT = "Score";
	const sf::String SCORE_LEVEL_TEXT = "Level";
	const sf::String SCORE_LINES_TEXT = "Lines";


	constexpr sf::Vector2f NEXT_PIECE_PANEL_SIZE = { (int)BLOCK_SIZE * 5.0f, (int)BLOCK_SIZE * 15.0f };
	constexpr sf::Vector2f NEXT_PIECE_PANEL_POSITION =
	{
		BOARD_POSITION.x + BOARD_WIDTH * BLOCK_SIZE + 50.0f,
		HOLD_PANEL_POSITION.y
	};
	const sf::String NEXT_PIECE_TEXT = "Next";


	constexpr size_t WINDOW_WIDTH = 200u + (int)HOLD_PANEL_SIZE.x + BOARD_WIDTH * BLOCK_SIZE + (int)NEXT_PIECE_PANEL_SIZE.x;
	constexpr size_t WINDOW_HEIGHT = 100u + BOARD_HEIGHT * BLOCK_SIZE;
	constexpr sf::Vector2u WINDOW_SIZE{ WINDOW_WIDTH, WINDOW_HEIGHT };
	constexpr char WINDOW_TITLE[] = "tetris-cpp";

	constexpr sf::Color CLEAR_COLOR = { 0, 0, 0 };

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


	constexpr std::array<int, 6> SELECTABLE_START_LEVELS =
	{
		0, 5, 10, 15, 20, 25
	};

	const sf::String TITLE_TEXT = "Tetris Clone";
	const sf::String GAME_OVER_TEXT = "Game Over";


	inline const sf::Font& getFont()
	{
		static sf::Font font;
		static bool isLoaded = font.openFromFile("../resources/kongtext.ttf");
		if (!isLoaded)
		{
			throw std::runtime_error("Failed to load font");
		}
		return font;
	}

#define FONT getFont()

}
