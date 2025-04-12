#pragma once
#include "Panel.h"
#include <array>
#include <queue>
#include <memory>
#include "Piece.h"


class NextPiecePanel : public Panel
{
public:
	NextPiecePanel();
	virtual void draw(sf::RenderWindow& window) override;
	void updateNextPieces(std::queue<Pieces::PieceType> nextPieces);
private:
	std::array<std::unique_ptr<Pieces::Piece>, 3> m_nextPieces;
};