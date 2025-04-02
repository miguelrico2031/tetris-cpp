#include "Board.h"
#include "Logger.h"


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

	void Board::draw(sf::RenderWindow& window)
	{
		drawBakcgroundGrid(window);
		drawFixedBlocks(window);
	}


	void Board::fixMovingPiece(const MovingPiece& piece)
	{
		const RotatedPiece& rotatedPiece = piece.getRotatedPiece();
		sf::Vector2i piecePosition = piece.getPosition();


		for (size_t row = 0; row < 4; row++)
		{
			for (size_t col = 0; col < 4; col++)
			{
				if (!rotatedPiece[row][col]) //only if there is a block
					continue;

				sf::Vector2i blockPosition = piecePosition + sf::Vector2i{ (int)col, (int)row };

				m_matrix[col + row * CONST::BOARD_WIDTH] = piece.getPiece();
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


	void Board::drawBakcgroundGrid(sf::RenderWindow& window)
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

		for (int row = 0; row < CONST::BOARD_HEIGHT; row++)
		{
			for (int col = 0; col < CONST::BOARD_WIDTH; col++)
			{
				Piece piece = m_matrix[col + row * CONST::BOARD_WIDTH];

				if (piece == Piece::None)
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