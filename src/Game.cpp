#include "Game.h"
#include "Logger.h"
#include "MenuScene.h"
#include "GameplayScene.h"

void Game::start() //add all scenes here and load first scene
{
	setScene<MenuScene>();
}

void Game::update(float dt) //update current scene
{
	m_currentScene->update(dt);
}

void Game::render() //render current scene
{
	m_currentScene->render(m_window);
}

void Game::handleEvents(const std::optional<sf::Event>& event) { }
