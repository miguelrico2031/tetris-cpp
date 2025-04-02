#include "GameplayScene.h"

void GameplayScene::load()
{
	m_movingPiece = new Pieces::MovingPiece(Pieces::Piece::T, { 00, 00 });

	m_board.print();

	m_board.fixMovingPiece(*m_movingPiece);

	delete m_movingPiece;
	m_movingPiece = nullptr;

	m_board.print();

}

void GameplayScene::update(float dt)
{
}

void GameplayScene::render(sf::RenderWindow& window)
{
	if (m_movingPiece != nullptr)
	{
		m_movingPiece->draw(window);
	}

	m_board.draw(window);
}

void GameplayScene::unload()
{
	delete m_movingPiece;
}
