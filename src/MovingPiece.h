#pragma once
#include "Pieces.h"
#include <SFML/Graphics.hpp>
#include <array>

namespace Pieces
{
	class MovingPiece
	{
	public:
		MovingPiece(Piece piece, sf::Vector2i position);

		inline Piece getPiece() const { return m_piece; }

		inline const RotatedPiece& getRotatedPiece() const { return Rotations::All[m_piece][m_rotation]; }
		inline sf::Vector2i getPosition() const { return m_position; }
		inline void setPosition(sf::Vector2i position) { m_position = position; }
		
		void rotate(bool right);
		void move(sf::Vector2i movement);
		void draw(sf::RenderWindow& window);

	private:
		Piece m_piece;
		int m_rotation;
		sf::Vector2i m_position; // top left corner of the piece (4x4 matrix)

		std::array<sf::RectangleShape, 4> m_blocks; //sfml shapes (for render only)
	};
}