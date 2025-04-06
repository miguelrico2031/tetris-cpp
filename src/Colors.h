#pragma once
#include "PieceType.h"
#include <SFML/Graphics.hpp>

namespace Pieces
{
	namespace Colors
	{

		const sf::Color None;
		const sf::Color O(255, 255, 0);
		const sf::Color I(0, 255, 255);
		const sf::Color S(0, 255, 0);
		const sf::Color Z(255, 0, 0);
		const sf::Color T(128, 0, 128);
		const sf::Color J(0, 0, 255);
		const sf::Color L(255, 165, 0);

		const sf::Color All[] = { None, O, I, S, Z, T, J, L };
	}

}