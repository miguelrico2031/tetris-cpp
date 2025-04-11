#pragma once
#include <array>
#include <vector>
#include "const.h"
#include "Piece.h"

	
class Board
{
public:
	Board(sf::Vector2f position);

	sf::Vector2i getDefaultMovingPieceSpawnPoint() const;
	bool isPieceInBounds(const Pieces::RotatedPiece& rotatedPiece, sf::Vector2i checkCoords) const;
	bool isPieceColliding(const Pieces::RotatedPiece& rotatedPiece, sf::Vector2i checkCoords) const;
	bool isRowFull(int row) const;
	bool anyFullRows() const;

	sf::Vector2f matrixCoordsToPosition(sf::Vector2i positionGrid) const; //receives matrix coordinates and returns the world space position
	sf::Vector2f matrixCoordsToPosition(int x, int y) const;
	void print() const;

	void draw(sf::RenderWindow& window);
	void fixPieceInMatrix(const Pieces::Piece piece, sf::Vector2i coords);
	//void clearRows();
	void clearBlock(sf::Vector2i coords);
	void moveClearedRowsDown();
	
	inline const std::vector<int> getFullRows() const { return m_fullRows; }

private:
	sf::Vector2f m_position;
	std::array<Pieces::PieceType, CONST::BOARD_SIZE> m_matrix = {}; //matrix represented as a buffer ([x][y] represented as [x + y * CONST::BOARD_WIDTH]
	std::array<sf::RectangleShape, CONST::BOARD_SIZE> m_backgroundGrid;
	sf::RectangleShape m_fixedBlock; //this is moved and drawn for each block in the matrix
	int m_minMatrixBlockDepth = CONST::BOARD_HEIGHT; //smallest y coord of a block in the matrix
	std::vector<int> m_fullRows;
	int m_clearedMinDepth;
	int m_clearedMaxDepth;

private:
	void drawBackgroundGrid(sf::RenderWindow& window);
	void drawFixedBlocks(sf::RenderWindow& window);
	void moveRowDown(int row, int targetRow);



};


