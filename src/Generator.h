#pragma once
#include "PieceType.h"
#include <array>
#include <queue>

namespace Pieces
{
	class Generator
	{
	public:
		Generator() { shuffleBag(); }
		PieceType getNextRandomPiece();
		PieceType holdPiece(PieceType piece);
		inline std::queue<PieceType> getNext3Pieces() const { return m_next3Pieces; }
	private:
		int m_nextPieceIndex = 0;
		std::array<PieceType, 7> m_pieceBag = { O, I, S, Z, T, J, L };
		std::queue<PieceType> m_next3Pieces;
		PieceType m_heldPiece = PieceType::None;
	private:
		void shuffleBag();
	};
}