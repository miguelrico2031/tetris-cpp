#include "GameOverScene.h"
#include "Logger.h"
#include "Game.h"
#include "const.h"
#include "MenuScene.h"
#include "Save.h"

GameOverScene::GameOverScene(Game* game)
	: Scene(game), m_buttonManager(game->getWindow()), m_titleText(CONST::FONT), m_scoreText(CONST::FONT)
{
}

void GameOverScene::load()
{
	Logger::log("GameOverScene loaded");

	m_titleText.setString(CONST::GAME_OVER_TEXT);
	m_titleText.setCharacterSize(30);
	m_titleText.setOrigin({ m_titleText.getLocalBounds().size / 2.0f });
	m_titleText.setPosition({ CONST::WINDOW_WIDTH / 2.0f, CONST::WINDOW_HEIGHT / 2.0f - 100.0f });
	m_titleText.setFillColor(sf::Color::Red);

	m_scoreText.setString("Score: " + std::to_string(m_game->getScore()));
	m_scoreText.setCharacterSize(30);
	m_scoreText.setOrigin({ m_scoreText.getLocalBounds().size / 2.0f });
	m_scoreText.setPosition({ CONST::WINDOW_WIDTH / 2.0f, CONST::WINDOW_HEIGHT / 2.0f });
	m_titleText.setFillColor(sf::Color::White);


	Button& menuBtn = m_buttonManager.addButton([this]() { saveAndGoToMenu(); },
		"Menu", { CONST::WINDOW_WIDTH / 2.0f, CONST::WINDOW_HEIGHT / 2.0f + 150.0f }, { 300, 100 }, 20, sf::Color::White, { 40, 90, 30 });

}

void GameOverScene::update(float dt)
{
	m_buttonManager.update(dt);
}

void GameOverScene::render(sf::RenderWindow& window)
{
	window.clear(CONST::CLEAR_COLOR);
	window.draw(m_titleText);
	window.draw(m_scoreText);
	m_buttonManager.render(window);
	window.display();
}

void GameOverScene::unload()
{
}

void GameOverScene::saveAndGoToMenu()
{
	int score = m_game->getScore();
	int highscore = Save::loadHighScore();
	if (score > highscore)
	{
		Save::saveHighScore(score);
		Logger::log("New highscore: " + std::to_string(score));
	}
	m_game->setScene<MenuScene>();
}
