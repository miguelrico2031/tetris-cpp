#include "MovingPiece.h"
#include "CONST.h"
#include "Board.h"
#include "Colors.h"
#include <algorithm>

namespace Pieces
{
	MovingPiece::MovingPiece(PieceType piece, sf::Vector2i coords, const Board* board)
		: m_piece(piece), m_coords(coords), m_board(board)
	{
		m_piece.setPosition(board->matrixCoordsToPosition(m_coords));
	}


	void MovingPiece::setCoords(sf::Vector2i coords)
	{
		m_coords = coords;
		m_piece.setPosition(m_board->matrixCoordsToPosition(m_coords));
	}


	void MovingPiece::moveCoords(sf::Vector2i movement)
	{
		sf::Vector2i newCoords = m_coords + movement;
		if(areCoordsInBounds(newCoords))
			setCoords(newCoords);
	}

	void MovingPiece::rotate(bool right)
	{
		m_piece.rotate(right);
	}

	bool MovingPiece::areCoordsInBounds(sf::Vector2i coords) const
	{
		const RotatedPiece& rotatedPiece = m_piece.getRotatedPiece();
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				if (!rotatedPiece[row][col])
					continue;

				sf::Vector2i blockCoords = coords + sf::Vector2i{col, row};

				if (blockCoords.x < 0 || blockCoords.x >= (int)CONST::BOARD_WIDTH || blockCoords.y >= (int)CONST::BOARD_HEIGHT)
					return false;
			}
		}
		return true;
	}

}
