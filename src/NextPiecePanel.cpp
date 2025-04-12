#include "NextPiecePanel.h"


NextPiecePanel::NextPiecePanel() : Panel()
{
	m_text.setString(CONST::NEXT_PIECE_TEXT);
	m_text.setCharacterSize(30);
	auto bounds = m_text.getLocalBounds();
	m_text.setPosition(getACenteredPositioninB(CONST::NEXT_PIECE_PANEL_SIZE, CONST::NEXT_PIECE_PANEL_POSITION, bounds.size, true));
}

void NextPiecePanel::draw(sf::RenderWindow& window)
{
	window.draw(m_text);
	for (auto& piece : m_nextPieces)
		if(piece != nullptr)
			piece->draw(window);
}

void NextPiecePanel::updateNextPieces(std::queue<Pieces::PieceType> nextPieces)
{
	sf::Vector2f position = CONST::NEXT_PIECE_PANEL_POSITION;
	position.y += m_text.getLocalBounds().size.y + CONST::BLOCK_SIZE * 2.0f;
	for (size_t i = 0; i < 3; i++)
	{
		auto pieceType = nextPieces.front();
		nextPieces.pop();
		m_nextPieces[i] = std::make_unique<Pieces::Piece>(pieceType);

		float width = pieceType == Pieces::O || pieceType == Pieces::I
			? 4.0f
			: 3.0f;


		sf::Vector2f size = sf::Vector2f
		{ width * (float)(int)CONST::BLOCK_SIZE,
		  2.0f * (float)(int)CONST::BLOCK_SIZE, };
		m_nextPieces[i]->setPosition(getACenteredPositioninB(CONST::NEXT_PIECE_PANEL_SIZE, CONST::NEXT_PIECE_PANEL_POSITION, size, false));
		m_nextPieces[i]->setPosition({ m_nextPieces[i]->getPosition().x, position.y });
		
		
		position.y += CONST::BLOCK_SIZE * 4.0f;
	}
}
