#include "Game.h"
#include "Logger.h"
#include "GameplayScene.h"
#include "const.h"

Game::Game()
{

}

Game::~Game()
{
	if (m_currentScene != nullptr)
	{
		m_currentScene->unload();
		m_currentScene = nullptr;
	}
	for (auto& [name, scene] : m_scenes)
	{
		delete scene;
	}
	m_scenes.clear();
}

void Game::start() //add all scenes here and load first scene
{
	Scene* scene = addScene<GameplayScene>();
	loadScene(scene);
}

void Game::update(float dt) //update current scene
{
	m_currentScene->update(dt);
}

void Game::render(sf::RenderWindow& window) //render current scene
{
	window.clear(CONST::CLEAR_COLOR);
	m_currentScene->render(window);
	window.display();
}

void Game::handleEvents(const std::optional<sf::Event>& event)
{

}

void Game::loadScene(std::string sceneName)
{
	auto it = m_scenes.find(sceneName);
	if (it == m_scenes.end())
	{
		Logger::logWarning("Scene not found: " + sceneName);
		return;
	}
	loadScene(it->second);

}

void Game::loadScene(Scene* scene)
{
	if (m_currentScene != nullptr)
	{
		m_currentScene->unload();
	}
	m_currentScene = scene;
	m_currentScene->load();
}