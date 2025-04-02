#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <map>

#include "Scene.h"
class Game
{
public:
	Game();
	~Game();
	void start();
	void update(float dt);
	void render(sf::RenderWindow& window);
	void handleEvents(const std::optional<sf::Event>& event);
	void loadScene(std::string sceneName);


private:
	Scene* m_currentScene = nullptr;
	std::unordered_map<std::string, Scene*> m_scenes;

private:
	template <typename SceneType> SceneType* addScene()
	{
		std::string sceneName = typeid(SceneType).name();
		SceneType* newScene = new SceneType(sceneName);
		m_scenes[sceneName] = newScene;
		return newScene;
	}

	void loadScene(Scene* scene);



};