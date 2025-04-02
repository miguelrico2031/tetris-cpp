#pragma once
#include "MovingPiece.h"
#include <array>
#include "CONST.h"

namespace Pieces {
	class Board
	{
	public:
		Board(sf::Vector2f position);

		void draw(sf::RenderWindow& window);
		void fixMovingPiece(const MovingPiece& piece);

		//debug
		void print();

	private:
		sf::Vector2f m_position;

		std::array<Piece, CONST::BOARD_SIZE> m_matrix = {Piece::None}; //matrix represented as a buffer ([x][y] represented as [x + y * CONST::BOARD_WIDTH]
		std::array<sf::RectangleShape, CONST::BOARD_SIZE> m_backgroundGrid;


	private:
		void drawBakcgroundGrid(sf::RenderWindow& window);
		void drawFixedBlocks(sf::RenderWindow& window);

		//receives matrix coordinates and returns the world space position
		sf::Vector2f matrixCoordsToPosition(sf::Vector2i positionGrid) const;
		sf::Vector2f matrixCoordsToPosition(int x, int y) const;

	};

}
