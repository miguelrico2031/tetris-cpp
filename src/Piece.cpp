#include "Piece.h"
#include "CONST.h"
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
			static sf::Texture tex("../textures/tex.png");
			block.setTexture(&tex);
		}
		setRotation(rotation);

	}

	void Piece::rotate(bool right)
	{
		int numRotations = Rotations::All[m_piece].size();
		if (right)
		{
			setRotation((m_rotation + 1) % numRotations);
		}
		else
		{
			setRotation((m_rotation - 1 + numRotations) % numRotations);
		}
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



				//set its color

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