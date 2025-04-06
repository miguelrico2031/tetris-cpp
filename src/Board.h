#pragma once
#include <array>
#include "CONST.h"
#include "PieceType.h"


namespace Pieces {
	
	class MovingPiece;
	
	class Board
	{
	public:
		Board(sf::Vector2f position);

		sf::Vector2i getDefaultMovingPieceSpawnPoint() const;
		void draw(sf::RenderWindow& window);
		bool isPieceColliding(const MovingPiece& movingPiece, sf::Vector2i checkCoords);
		void fixMovingPiece(const MovingPiece& movingPiece);
		//receives matrix coordinates and returns the world space position
		sf::Vector2f matrixCoordsToPosition(sf::Vector2i positionGrid) const;
		sf::Vector2f matrixCoordsToPosition(int x, int y) const;
		void print();

	private:
		sf::Vector2f m_position;
		std::array<PieceType, CONST::BOARD_SIZE> m_matrix = {}; //matrix represented as a buffer ([x][y] represented as [x + y * CONST::BOARD_WIDTH]
		std::array<sf::RectangleShape, CONST::BOARD_SIZE> m_backgroundGrid;
		int m_minMatrixBlockDepth = CONST::BOARD_HEIGHT; //smallest y coord of a block in the matrix

	private:
		void drawBackgroundGrid(sf::RenderWindow& window);
		void drawFixedBlocks(sf::RenderWindow& window);



	};

}
