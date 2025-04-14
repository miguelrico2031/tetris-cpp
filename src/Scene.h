#pragma once
#include <SFML/Graphics.hpp>

class Game;

class Scene
{
public:
	Scene(Game* game) : m_game(game) {}
	virtual void load() = 0;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void unload() = 0;
protected:
	Game* m_game = nullptr;
};

