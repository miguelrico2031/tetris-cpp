#pragma once
#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "const.h"


class Panel
{
public:
	Panel() : m_text(CONST::FONT){}
	virtual void draw(sf::RenderWindow& window) = 0;
protected:
	sf::Text m_text;
protected:
	inline static sf::Vector2f getACenteredPositioninB(sf::Vector2f bSize,
		sf::Vector2f bPosition,
		sf::Vector2f aSize,
		bool horizontalOnly = false)
	{
		sf::Vector2f newPos = bPosition;
		newPos.x += bSize.x / 2.0f - aSize.x / 2.0f;
		if (!horizontalOnly)
			newPos.y += bSize.y / 2.0f - aSize.y / 2.0f;
		return newPos;
	}
};