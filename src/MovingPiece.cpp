#include "MovingPiece.h"
#include "CONST.h"
#include "Board.h"
#include "Colors.h"
#include <algorithm>

namespace Pieces
{
	MovingPiece::MovingPiece(PieceType piece, sf::Vector2i coords, const Board& board)
		: m_piece(piece), m_coords(coords), m_board(board)
	{
		m_piece.setPosition(m_board.matrixCoordsToPosition(m_coords));
	}


	void MovingPiece::setCoords(sf::Vector2i coords)
	{
		m_coords = coords;
		m_piece.setPosition(m_board.matrixCoordsToPosition(m_coords));
	}
}
