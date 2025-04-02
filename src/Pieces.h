#pragma once
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>

namespace Pieces
{
	enum Piece
	{
		None = 0,
		O = 1,
		I = 2,
		S = 3,
		Z = 4,
		T = 5,
		J = 6,
		L = 7
	};

	using RotatedPiece = std::array<std::array<bool, 4>, 4>;
	using RotatedPieceList = std::vector<RotatedPiece>;
	namespace Rotations
	{
		const RotatedPieceList None;

		const RotatedPieceList O =
		{
			{{
				{{0, 0, 0, 0}},
				{{0, 1, 1, 0}},
				{{0, 1, 1, 0}},
				{{0, 0, 0, 0}},
			}}
		};

		const RotatedPieceList I =
		{
			{{
				{{0, 1, 0, 0,}},
				{{0, 1, 0, 0,}},
				{{0, 1, 0, 0,}},
				{{0, 1, 0, 0,}},
			}},
			{{
				{{0, 0, 0, 0,}},
				{{0, 0, 0, 0,}},
				{{1, 1, 1, 1,}},
				{{0, 0, 0, 0,}},
			}}
		};

		const RotatedPieceList S =
		{
			{{
				{{0, 0, 0, 0}},
				{{0, 0, 1, 1}},
				{{0, 1, 1, 0}},
				{{0, 0, 0, 0}},
			}},
			{{
				{{0, 0, 0, 0}},
				{{0, 1, 0, 0}},
				{{0, 1, 1, 0}},
				{{0, 0, 1, 0}},
			}}
		};

		const RotatedPieceList Z =
		{
			{{
				{{0, 0, 0, 0}},
				{{1, 1, 0, 0}},
				{{0, 1, 1, 0}},
				{{0, 0, 0, 0}},
			}},
			{{
				{{0, 0, 0, 0}},
				{{0, 0, 1, 0}},
				{{0, 1, 1, 0}},
				{{0, 1, 0, 0}},
			}}
		};

		const RotatedPieceList T =
		{
			{{
				{{0, 0, 0, 0}},
				{{0, 0, 0, 0}},
				{{0, 1, 0, 0}},
				{{1, 1, 1, 0}},
			}},
			{{
				{{0, 0, 0, 0}},
				{{0, 0, 1, 0}},
				{{0, 1, 1, 0}},
				{{0, 0, 1, 0}},
			}},
			{{
				{{0, 0, 0, 0}},
				{{1, 1, 1, 0}},
				{{0, 1, 0, 0}},
				{{0, 0, 0, 0}},
			}},
			{{
				{{0, 0, 0, 0}},
				{{1, 0, 0, 0}},
				{{1, 1, 0, 0}},
				{{1, 0, 0, 0}},
			}}
		};

		const RotatedPieceList J =
		{
			{{
				{{0, 0, 0, 0}},
				{{0, 0, 1, 0}},
				{{0, 0, 1, 0}},
				{{0, 1, 1, 0}},
			}},
			{{
				{{0, 0, 0, 0}},
				{{1, 1, 1, 0}},
				{{0, 0, 1, 0}},
				{{0, 0, 0, 0}},
			}},
			{{
				{{0, 1, 1, 0}},
				{{0, 1, 0, 0}},
				{{0, 1, 0, 0}},
				{{0, 0, 0, 0}},
			}},
			{{
				{{0, 0, 0, 0}},
				{{0, 1, 0, 0}},
				{{0, 1, 1, 1}},
				{{0, 0, 0, 0}},
			}}
		};

		const RotatedPieceList L =
		{
			{{
				{{0, 0, 0, 0}},
				{{0, 1, 0, 0}},
				{{0, 1, 0, 0}},
				{{0, 1, 1, 0}},
			}},
			{{
				{{0, 0, 0, 0}},
				{{0, 0, 0, 1}},
				{{0, 1, 1, 1}},
				{{0, 0, 0, 0}},
			}},
			{{
				{{0, 1, 1, 0}},
				{{0, 0, 1, 0}},
				{{0, 0, 1, 0}},
				{{0, 0, 0, 0}},
			}},
			{{
				{{0, 0, 0, 0}},
				{{0, 0, 0, 0}},
				{{0, 1, 1, 1}},
				{{0, 1, 0, 0}},
			}}
		};

		const RotatedPieceList All[] = {None, O, I, S, Z, T, J, L };
	}

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


