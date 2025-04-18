#pragma once
#include "PieceType.h"
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <array>

class Board;
namespace Pieces
{

	class MovingPiece
	{
	public:
		MovingPiece(PieceType piece, sf::Vector2i coords, const Board& board);
		inline Piece& getPiece() { return m_piece; }
		inline const Piece& getPiece() const { return m_piece; }
		inline sf::Vector2i getCoords() const { return m_coords; }
		void setCoords(sf::Vector2i coords);
	private:
		Piece m_piece;
		sf::Vector2i m_coords; //board matrix coords
		const Board& m_board;
	private:

	};
}