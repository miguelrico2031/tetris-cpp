#include "Piece.h"
#include "const.h"
#include "Colors.h"

namespace Pieces
{

	Piece::Piece(PieceType piece, sf::Vector2f position, int rotation)
		: m_piece(piece), m_position(position)
	{
		sf::Color color = Colors::All[piece];
		for (auto& block : m_blocks)
		{
			block.setSize(CONST::BLOCK_SIZE_V);
			block.setFillColor(color);
			static sf::Texture tex("../resources/tex.png");
			block.setTexture(&tex);
		}
		setRotation(rotation);

	}

	int Piece::getNextRotation(bool right) const
	{
		static int numRotations = Rotations::All[m_piece].size(); //4 constexpr
		if (right)
		{
			return (m_rotation + 1) % numRotations;
		}
		else
		{
			return (m_rotation - 1 + numRotations) % numRotations;
		}
	}

	const RotatedPiece& Piece::getNextRotatedPiece(bool right) const
	{
		return Rotations::All[m_piece][getNextRotation(right)];
	}

	void Piece::rotate(bool right)
	{
		setRotation(getNextRotation(right));
	}

	void Piece::setRotation(int rotation)
	{
		m_rotation = rotation;

		const RotatedPiece& rotatedPiece = getRotatedPiece();
		size_t blockIndex = 0;

		for (size_t row = 0; row < 4; row++)
		{
			for (size_t col = 0; col < 4; col++)
			{
				if (!rotatedPiece[row][col])
					continue;

				//for each 1/true in the RotatedPieceMatrix, get the block ref
				auto& block = m_blocks[blockIndex++];
				//set its position using the displacement
				sf::Vector2f blockPosition =
				{
					m_position.x + ((float)col * (float)CONST::BLOCK_SIZE),
					m_position.y + ((float)row * (float)CONST::BLOCK_SIZE)
				};
				block.setPosition(blockPosition);
			}
		}
	}

	void Piece::move(sf::Vector2f movement)
	{
		m_position += movement;
		for (auto& block : m_blocks)
		{
			block.move(movement);
		}
	}

	void Piece::setPosition(sf::Vector2f position)
	{
		move(position - m_position);
	}


	void Piece::draw(sf::RenderWindow& window)
	{

		for (auto& block : m_blocks)
		{
			window.draw(block);
		}
	}


}