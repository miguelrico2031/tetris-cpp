#include "MenuScene.h"
#include "Logger.h"
#include "Game.h"
#include "Save.h"

MenuScene::MenuScene(Game* game)
	: Scene(game), m_buttonManager(game->getWindow()), m_titleText(CONST::FONT), m_highscoreText(CONST::FONT)
{
}

void MenuScene::load()
{  
   Logger::log("MenuScene loaded");  

   m_titleText.setString(CONST::TITLE_TEXT);
   m_titleText.setCharacterSize(60);
   m_titleText.setOrigin({ m_titleText.getLocalBounds().size.x / 2.0f, 0.0f });
   m_titleText.setPosition({ CONST::WINDOW_WIDTH / 2.0f, 100.0f });
   m_titleText.setFillColor(sf::Color::White);

   m_highscoreText.setString("Highscore: " + std::to_string(Save::loadHighScore()));
   m_highscoreText.setCharacterSize(30);
   m_highscoreText.setOrigin({ m_highscoreText.getLocalBounds().size.x / 2.0f, m_highscoreText.getLocalBounds().size.y });
   m_highscoreText.setPosition({ CONST::WINDOW_WIDTH / 2.0f, CONST::WINDOW_HEIGHT - 150.0f });
   m_titleText.setFillColor(sf::Color::White);


   Button& playBtn = m_buttonManager.addButton([this]() { startGameplay(); },  
       "Play", {CONST::WINDOW_WIDTH/2.0f, CONST::WINDOW_HEIGHT / 2.0f - 100}, {300, 100}, 20, sf::Color::White, {40, 90, 30});


   sf::String levelTxt = "Level: " + std::to_string(CONST::SELECTABLE_START_LEVELS[m_selectedLevelIndex]);
   Button& levelBtn = m_buttonManager.addButton([this]() { toggleLevel(); },  
	   levelTxt, { CONST::WINDOW_WIDTH / 2.0f, CONST::WINDOW_HEIGHT / 2.0f + 100 }, { 300, 100 }, 20, sf::Color::White, {75, 75, 75});

   m_levelButtonText = &levelBtn.getText();

}


void MenuScene::update(float dt)
{
	m_buttonManager.update(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		m_game->setScene<GameplayScene>();
	}
}

void MenuScene::render(sf::RenderWindow& window)
{
	window.clear(CONST::CLEAR_COLOR);
	m_buttonManager.render(window);
	window.draw(m_titleText);
	window.draw(m_highscoreText);
	window.display();
}

void MenuScene::unload()
{
	Logger::log("MenuScene unloaded");
}

void MenuScene::startGameplay()
{
	m_game->setStartLevel(CONST::SELECTABLE_START_LEVELS[m_selectedLevelIndex]);
	m_game->setScene<GameplayScene>();
}

void MenuScene::toggleLevel()
{
	m_selectedLevelIndex = (m_selectedLevelIndex + 1) % CONST::SELECTABLE_START_LEVELS.size();
	m_levelButtonText->setString("Level: " + std::to_string(CONST::SELECTABLE_START_LEVELS[m_selectedLevelIndex]));
}
