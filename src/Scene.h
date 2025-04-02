#pragma once

#include <SFML/Graphics.hpp>
#include <string>


class Scene
{
public:
	Scene(std::string name) : m_name(name) {}

	virtual void load() = 0;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void unload() = 0;

	inline const std::string& getName() const { return m_name; }
protected:
	std::string m_name;
};

