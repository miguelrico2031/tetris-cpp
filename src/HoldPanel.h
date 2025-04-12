#pragma once
#include "Panel.h"
#include <memory>
#include "Piece.h"



class HoldPanel : public Panel
{
public:
	HoldPanel();
	virtual void draw(sf::RenderWindow& window) override;
	void setHeldPiece(Pieces::PieceType pieceType);
private:
	std::unique_ptr<Pieces::Piece> m_heldPiece = nullptr;
};