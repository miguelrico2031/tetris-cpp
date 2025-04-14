#include "GameplayScene.h"
#include "Game.h"
#include "Logger.h"
#include "MovingPieceState.h"
#include "MenuScene.h"	
#include "GameOverScene.h"	
#include <algorithm>


GameplayScene::GameplayScene(Game* game)
	: Scene(game), m_level(game->getStartLevel()), m_scorePanel(game->getStartLevel()), m_buttonManager(game->getWindow())
{
}

void GameplayScene::load()
{
	Logger::log("GameplayScene loaded");

	auto& pauseButton = m_buttonManager.addButton([this]() { togglePause(); }, "Pause",
		{ CONST::NEXT_PIECE_PANEL_POSITION.x + CONST::NEXT_PIECE_PANEL_SIZE.x / 2.0f, CONST::NEXT_PIECE_PANEL_POSITION.y + CONST::NEXT_PIECE_PANEL_SIZE.y + 10.0f },
		{ CONST::NEXT_PIECE_PANEL_SIZE.x, 60 }, 20, sf::Color::White, { 75, 75, 75 });

	m_pauseButtonText = &pauseButton.getText();

	m_buttonManager.addButton([this]() { goToMenu(); }, "Menu",
		{ CONST::NEXT_PIECE_PANEL_POSITION.x + CONST::NEXT_PIECE_PANEL_SIZE.x / 2.0f, CONST::NEXT_PIECE_PANEL_POSITION.y + CONST::NEXT_PIECE_PANEL_SIZE.y + 100.0f },
		{ CONST::NEXT_PIECE_PANEL_SIZE.x, 60 }, 20, sf::Color::White, { 40, 90, 30 });


	m_nextPiecePanel.updateNextPieces(m_generator.getNext3Pieces());
	SetState<MovingPieceState>();
}

void GameplayScene::update(float dt)
{
	m_buttonManager.update(dt);
	if (m_paused)
		return;
	if (m_currentState != nullptr)
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

	m_buttonManager.render(window);

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

void GameplayScene::togglePause()
{
	m_paused = !m_paused;
	if (m_pauseButtonText != nullptr)
		m_pauseButtonText->setString(m_paused ? "Resume" : "Pause");
}

void GameplayScene::goToMenu()
{
	m_currentState = nullptr;
	m_game->setScene<MenuScene>();
}

