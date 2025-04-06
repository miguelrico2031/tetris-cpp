#include "Board.h"
#include "Logger.h"
#include "MovingPiece.h"
#include "Colors.h"


namespace Pieces
{
	Board::Board(sf::Vector2f position)
		: m_position(position)
	{
		sf::RectangleShape cell(CONST::BLOCK_SIZE_V);
		cell.setFillColor(CONST::CLEAR_COLOR);
		cell.setOutlineColor(CONST::BOARD_BACKGROUND_GRID_COLOR);
		cell.setOutlineThickness(CONST::BOARD_BACKGROUND_GRID_THICKNESS);
		m_backgroundGrid.fill(cell);
		for (size_t row = 0; row < CONST::BOARD_HEIGHT; row++)
		{
			for (size_t col = 0; col < CONST::BOARD_WIDTH; col++)
			{
				m_backgroundGrid[col + row * CONST::BOARD_WIDTH].setPosition(matrixCoordsToPosition(col, row));
			}
		}
	}

	sf::Vector2i Board::getDefaultMovingPieceSpawnPoint() const
	{
		return { CONST::BOARD_WIDTH / 2 - 2, 0 };
	}

	void Board::draw(sf::RenderWindow& window)
	{
		drawBackgroundGrid(window);
		drawFixedBlocks(window);
	}

	bool Board::isPieceColliding(const MovingPiece& movingPiece, sf::Vector2i checkCoords)
	{
		if(checkCoords.y + 4 < m_minMatrixBlockDepth)
			return false;

		const RotatedPiece& rotatedPiece = movingPiece.getPiece().getRotatedPiece();

		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				if (!rotatedPiece[row][col]) //only if there is a block
					continue;
				sf::Vector2i blockCoords = checkCoords + sf::Vector2i{ col, row }; //block
				
				assert(blockCoords.x >= 0 && blockCoords.x < CONST::BOARD_WIDTH
					&& blockCoords.y >= 0 && blockCoords.y < CONST::BOARD_HEIGHT,
					"BLOCK COORDS OUT OF BOARD BOUNDS!");

				//check collision with board matrix
				if (m_matrix[blockCoords.x + blockCoords.y * CONST::BOARD_WIDTH] != None)
				{
					return true;
				}
			}
		}
		return false;

		for (int row = m_minMatrixBlockDepth; row < CONST::BOARD_HEIGHT; row++)
		{
			for (int col = 0; col < CONST::BOARD_WIDTH; col++)
			{
				PieceType piece = m_matrix[col + row * CONST::BOARD_WIDTH];
				if (piece == None) continue;

			}
		}
	}


	void Board::fixMovingPiece(const MovingPiece& movingPiece)
	{
		const Piece& piece = movingPiece.getPiece();
		const RotatedPiece& rotatedPiece = piece.getRotatedPiece();



		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				if (!rotatedPiece[row][col]) //only if there is a block
					continue;

				sf::Vector2i blockPosition = movingPiece.getCoords() + sf::Vector2i{col, row};

				if (blockPosition.y < m_minMatrixBlockDepth)
					m_minMatrixBlockDepth = blockPosition.y;

				m_matrix[blockPosition.x + blockPosition.y * CONST::BOARD_WIDTH] = piece.getPieceType();
			}
		}
	}

	void Board::print()
	{
		std::string print = "\n";

		for (size_t row = 0; row < CONST::BOARD_HEIGHT; row++)
		{
			for (size_t col = 0; col < CONST::BOARD_WIDTH; col++)
				print += std::to_string(m_matrix[col + row * CONST::BOARD_WIDTH]) + " ";

			print += "\n";
		}

		Logger::log(print);
	}


	void Board::drawBackgroundGrid(sf::RenderWindow& window)
	{
		for (const auto& cell : m_backgroundGrid)
			window.draw(cell);
	}

	void Board::drawFixedBlocks(sf::RenderWindow& window)
	{
		static sf::RectangleShape block(CONST::BLOCK_SIZE_V);
		static sf::Texture tex("../textures/tex.png");
		block.setTexture(&tex);
		static sf::Vector2f offset = { CONST::BOARD_BACKGROUND_GRID_THICKNESS / 2.0f, CONST::BOARD_BACKGROUND_GRID_THICKNESS / 2.0f };

		for (int row = m_minMatrixBlockDepth; row < CONST::BOARD_HEIGHT; row++)
		{
			for (int col = 0; col < CONST::BOARD_WIDTH; col++)
			{
				PieceType piece = m_matrix[col + row * CONST::BOARD_WIDTH];

				if (piece == PieceType::None)
					continue;

				block.setPosition(matrixCoordsToPosition(col, row) - offset);
				block.setFillColor(Colors::All[piece]);
				window.draw(block);
			}
		}
	}

	sf::Vector2f Board::matrixCoordsToPosition(sf::Vector2i positionGrid) const
	{
		return matrixCoordsToPosition(positionGrid.x, positionGrid.y);
	}

	sf::Vector2f Board::matrixCoordsToPosition(int x, int y) const
	{
		constexpr static float SIZE = (float)CONST::BLOCK_SIZE;
		return m_position + sf::Vector2f{ (float)x, (float)y } * SIZE;
	}

}