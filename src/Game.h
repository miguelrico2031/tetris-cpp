#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Scene.h"
class Game
{
public:
	Game(sf::RenderWindow& window) : m_window(window) {}
	void start();
	void update(float dt);
	void render();
	void handleEvents(const std::optional<sf::Event>& event);

	inline sf::RenderWindow& getWindow() { return m_window; }

	template <typename SceneType>
	inline void setScene()
	{
		if (m_currentScene != nullptr)
			m_currentScene->unload();
		m_currentScene = std::make_unique<SceneType>(this);
		m_currentScene->load();
	}

	inline int getStartLevel() const { return m_startLevel; }
	inline void setStartLevel(int level) { m_startLevel = level; }

	inline int getScore() const { return m_score; }
	inline void setScore(int score) { m_score = score; }
private:
	sf::RenderWindow& m_window;
	std::unique_ptr<Scene> m_currentScene = nullptr;
	int m_startLevel = 0;
	int m_score = 0;
};