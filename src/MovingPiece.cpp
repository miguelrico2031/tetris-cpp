#include "MovingPiece.h"
#include "CONST.h"

namespace Pieces
{
	MovingPiece::MovingPiece(Piece piece, sf::Vector2i position)
		: m_piece(piece), m_position(position), m_rotation(0)
	{
		size_t i = 0;
		const RotatedPiece& rotatedPiece = getRotatedPiece();
		sf::Color color = Colors::All[piece];

		size_t blockIndex = 0;

		for (size_t row = 0; row < 4; row++)
		{
			for (size_t col = 0; col < 4; col++)
			{
				if (!rotatedPiece[row][col])
					continue;

				//for each 1/true in the RotatedPieceMatrix, create one block 
				m_blocks[blockIndex] = sf::RectangleShape(CONST::BLOCK_SIZE_V);
				auto& block = m_blocks[blockIndex];
				blockIndex++;
				//set its position using the displacement
				sf::Vector2f blockPosition =
				{
					m_position.x + (col * (float)(int)CONST::BLOCK_SIZE),
					m_position.y + (row * (float)(int)CONST::BLOCK_SIZE)
				};
				block.setPosition(blockPosition);



				//set its color
				block.setFillColor(color);

			}
		}

	}




	void MovingPiece::rotate(bool right)
	{
		int numRotations = Rotations::All[m_piece].size();
		if (right)
		{
			m_rotation = (m_rotation + 1) % numRotations;
		}
		else
		{
			m_rotation = (m_rotation - 1 + numRotations) % numRotations;
		}
	}

	void MovingPiece::move(sf::Vector2i movement)
	{
		m_position += movement;
		for (auto& block : m_blocks)
		{
			block.move(static_cast<sf::Vector2f>(movement));
		}
	}

	void MovingPiece::draw(sf::RenderWindow& window)
	{
		for (auto& block : m_blocks)
		{
			window.draw(block);
		}
	}



}
