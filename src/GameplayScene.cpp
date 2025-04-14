#include "GameplayScene.h"
#include "Game.h"
#include "Logger.h"
#include "MovingPieceState.h"
#include "MenuScene.h"	
#include "GameOverScene.h"	
#include <algorithm>


GameplayScene::GameplayScene(Game* game)
	: Scene(game), m_level(game->getStartLevel()), m_scorePanel(game->getStartLevel())
{
}

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
	window.clear(CONST::CLEAR_COLOR);


	m_board.draw(window);
	if (m_currentState != nullptr)
		m_currentState->render(window);

	m_holdPanel.draw(window);
	m_scorePanel.draw(window);
	m_nextPiecePanel.draw(window);

	window.display();
}


void GameplayScene::unload()
{
	Logger::log("GameplayScene unloaded");
}

void GameplayScene::SetGameOver()
{
	m_currentState = nullptr;
	m_game->setScore(m_level.getScore());
	m_game->setScene<GameOverScene>();
}

