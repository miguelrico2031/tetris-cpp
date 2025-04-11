#include "Board.h"
#include "Logger.h"
#include "Piece.h"
#include "Colors.h"

Board::Board(sf::Vector2f position)
	: m_position(position)
{
	static sf::Texture tex("../textures/tex.png");
	m_fixedBlock.setTexture(&tex);
	m_fixedBlock.setSize(CONST::BLOCK_SIZE_V);

	sf::RectangleShape cell(CONST::BLOCK_SIZE_V);
	cell.setFillColor(CONST::CLEAR_COLOR);
	cell.setOutlineColor(CONST::BOARD_BACKGROUND_GRID_COLOR);
	cell.setOutlineThickness(CONST::BOARD_BACKGROUND_GRID_THICKNESS);

	m_backgroundGrid.fill(cell);
	for (size_t row = 0; row < CONST::BOARD_HEIGHT; row++)
	{
		for (size_t col = 0; col < CONST::BOARD_WIDTH; col++)
		{
			sf::Vector2f position = m_position + sf::Vector2f{ (float)col, (float)row } *(float)CONST::BLOCK_SIZE;
			m_backgroundGrid[col + row * CONST::BOARD_WIDTH].setPosition(position);
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

bool Board::isPieceInBounds(const Pieces::RotatedPiece& rotatedPiece, sf::Vector2i checkCoords) const
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (!rotatedPiece[row][col])
				continue;

			sf::Vector2i blockCoords = checkCoords + sf::Vector2i{ col, row };

			if (blockCoords.x < 0 || blockCoords.x >= (int)CONST::BOARD_WIDTH || blockCoords.y >= (int)CONST::BOARD_HEIGHT)
				return false;
		}
	}
	return true;
}

bool Board::isPieceColliding(const Pieces::RotatedPiece& rotatedPiece, sf::Vector2i checkCoords) const
{
	if (checkCoords.y + 4 < m_minMatrixBlockDepth)
		return false;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (!rotatedPiece[row][col]) //only if there is a block
				continue;
			sf::Vector2i blockCoords = checkCoords + sf::Vector2i{ col, row }; //block

			assert(blockCoords.x >= 0 && blockCoords.x < CONST::BOARD_WIDTH
				&& blockCoords.y >= 0 && blockCoords.y < CONST::BOARD_HEIGHT);

			//check collision with board matrix
			if (m_matrix[blockCoords.x + blockCoords.y * CONST::BOARD_WIDTH] != Pieces::None)
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
			Pieces::PieceType piece = m_matrix[col + row * CONST::BOARD_WIDTH];
			if (piece == Pieces::None) continue;

		}
	}
}

bool Board::isRowFull(int row) const
{
	for (int col = 0; col < CONST::BOARD_WIDTH; col++)
	{
		Pieces::PieceType piece = m_matrix[col + row * CONST::BOARD_WIDTH];
		if (piece == Pieces::None) return false;
	}
	return true;
}

bool Board::anyFullRows() const
{
	return !m_fullRows.empty();
}


void Board::fixPieceInMatrix(const Pieces::Piece piece, sf::Vector2i coords)
{
	const Pieces::RotatedPiece& rotatedPiece = piece.getRotatedPiece();

	m_fullRows.clear();

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (!rotatedPiece[row][col]) //only if there is a block
				continue;

			sf::Vector2i blockCoords = coords + sf::Vector2i{ col, row };

			if (blockCoords.y < m_minMatrixBlockDepth)
				m_minMatrixBlockDepth = blockCoords.y;

			m_matrix[blockCoords.x + blockCoords.y * CONST::BOARD_WIDTH] = piece.getPieceType();
			if(isRowFull(blockCoords.y))
				m_fullRows.push_back(blockCoords.y);
		}
	}

	if (m_fullRows.empty())
		return;

	m_clearedMinDepth = CONST::BOARD_HEIGHT;
	m_clearedMaxDepth = -1;

	for (int row : m_fullRows)
	{
		if (row < m_clearedMinDepth)
			m_clearedMinDepth = row;
		if (row > m_clearedMaxDepth)
			m_clearedMaxDepth = row;
	}
}

//void Board::clearRows()
//{
//	if (m_fullRows.empty())
//		return;
//	//clear the rows setting each cell to None
//	for (int row : m_fullRows)
//	{
//		for (int col = 0; col < CONST::BOARD_WIDTH; col++)
//		{
//			m_matrix[col + row * CONST::BOARD_WIDTH] = Pieces::None;
//		}
//	}
//}

void Board::clearBlock(sf::Vector2i coords)
{
	m_matrix[coords.x + coords.y * CONST::BOARD_WIDTH] = Pieces::None;
}

void Board::moveClearedRowsDown()
{
	//if the highest (least deep) row cleared was the highest row with fixed blocks in the matrix,
	//there is no blocks above that need to be lowered
	if (m_clearedMinDepth <= m_minMatrixBlockDepth)
	{
		m_minMatrixBlockDepth += m_fullRows.size();
		return;
	}

	//for each row above the cleared rows, move them down
	for (int row = m_clearedMinDepth - 1; row >= m_minMatrixBlockDepth; row--)
	{
		moveRowDown(row, m_clearedMaxDepth);
		m_clearedMaxDepth--;
	}
	m_minMatrixBlockDepth += m_fullRows.size();
	m_fullRows.clear();
}

void Board::moveRowDown(int row, int targetRow)
{
	for (int col = 0; col < CONST::BOARD_WIDTH; col++)
	{
		m_matrix[col + targetRow * CONST::BOARD_WIDTH] = m_matrix[col + row * CONST::BOARD_WIDTH];
		m_matrix[col + row * CONST::BOARD_WIDTH] = Pieces::None;
	}
}


void Board::print() const
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
	for (int row = m_minMatrixBlockDepth; row < CONST::BOARD_HEIGHT; row++)
	{
		for (int col = 0; col < CONST::BOARD_WIDTH; col++)
		{
			Pieces::PieceType piece = m_matrix[col + row * CONST::BOARD_WIDTH];

			if (piece == Pieces::PieceType::None)
				continue;

			m_fixedBlock.setPosition(matrixCoordsToPosition(col, row));
			m_fixedBlock.setFillColor(Pieces::Colors::All[piece]);
			window.draw(m_fixedBlock);
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
	constexpr static sf::Vector2f offset =
	{
		CONST::BOARD_BACKGROUND_GRID_THICKNESS / 2.0f,
		CONST::BOARD_BACKGROUND_GRID_THICKNESS / 2.0f
	};

	return m_position + sf::Vector2f{ (float)x, (float)y } *SIZE - offset;
}

