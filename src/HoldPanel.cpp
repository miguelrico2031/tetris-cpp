#include "HoldPanel.h"
#include "const.h"



HoldPanel::HoldPanel() : Panel()
{
	m_text.setString(CONST::HOLD_PANEL_TEXT);
	m_text.setCharacterSize(30);
	auto bounds = m_text.getLocalBounds();
	m_text.setPosition(getACenteredPositioninB(CONST::HOLD_PANEL_SIZE, CONST::HOLD_PANEL_POSITION, bounds.size, true));
}


void HoldPanel::draw(sf::RenderWindow& window)
{
	window.draw(m_text);
	if (m_heldPiece != nullptr)
		m_heldPiece->draw(window);
}

void HoldPanel::setHeldPiece(Pieces::PieceType pieceType)
{
	if (pieceType == Pieces::None)
	{
		m_heldPiece = nullptr;
		return;
	}
	m_heldPiece = std::make_unique<Pieces::Piece>(pieceType, CONST::HOLD_PANEL_POSITION);

	float width = pieceType == Pieces::O || pieceType == Pieces::I
		? 4.0f
		: 3.0f;

	sf::Vector2f size = sf::Vector2f
	{ width * (float)(int)CONST::BLOCK_SIZE,
	  2.0f * (float)(int)CONST::BLOCK_SIZE, };
	m_heldPiece->setPosition(getACenteredPositioninB(CONST::HOLD_PANEL_SIZE, CONST::HOLD_PANEL_POSITION, size));
}
