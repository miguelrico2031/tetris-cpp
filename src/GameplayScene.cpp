#include "GameplayScene.h"
#include "Logger.h"
#include <algorithm>
#include "MovingPieceState.h"


void GameplayScene::load()
{
	Logger::log("GameplayScene loaded");
	m_nextPiecePanel.updateNextPieces(m_generator.getNext3Pieces());
	SetState<MovingPieceState>();
}

void GameplayScene::update(float dt)
{
	if(m_currentState != nullptr)
		m_currentState->update(dt);
}

void GameplayScene::render(sf::RenderWindow& window)
{
	m_board.draw(window);
	if (m_currentState != nullptr)
		m_currentState->render(window);

	m_holdPanel.draw(window);
	m_scorePanel.draw(window);
	m_nextPiecePanel.draw(window);
}


void GameplayScene::unload()
{
	Logger::log("GameplayScene unloaded");
}

