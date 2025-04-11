#pragma once
#include "PieceType.h"
#include <array>

namespace Pieces
{
	class Generator
	{
	public:
		Generator() { shuffleBag(); }
		PieceType getNextRandomPiece();
		PieceType holdPiece(PieceType piece);
		
	private:
		int m_nextPieceIndex = 0;
		std::array<PieceType, 7> m_pieceBag = { O, I, S, Z, T, J, L };
		PieceType m_heldPiece = PieceType::None;
	private:
		void shuffleBag();
	};
}