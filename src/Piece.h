#pragma once
#include "PieceType.h"
#include "Rotations.h"
#include <SFML/Graphics.hpp>

namespace Pieces
{
	class Piece
	{
	public:
		Piece(PieceType piece, sf::Vector2f position = { 0, 0 }, int rotation = 0);
		inline PieceType getPieceType() const { return m_piece; }
		inline const RotatedPiece& getRotatedPiece() const { return Rotations::All[m_piece][m_rotation]; }
		inline int getRotation() const { return m_rotation; }
		inline sf::Vector2f getPosition() const { return m_position; }

		int getNextRotation(bool right) const;
		const RotatedPiece& getNextRotatedPiece(bool right) const;
		void rotate(bool right);
		void setRotation(int rotation);
		void move(sf::Vector2f movement);
		void setPosition(sf::Vector2f position);
		void draw(sf::RenderWindow& window);


	private:
		PieceType m_piece;
		sf::Vector2f m_position; // top left corner position
		int m_rotation;
		std::array<sf::RectangleShape, 4> m_blocks;
	private:
	};
}