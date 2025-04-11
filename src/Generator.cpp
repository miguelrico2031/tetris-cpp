#include "Generator.h"
#include <algorithm>
#include <random>
#include "Logger.h"

namespace Pieces
{
	PieceType Generator::getNextRandomPiece()
	{
		if (m_nextPieceIndex >= m_pieceBag.size())
		{
			shuffleBag();
			m_nextPieceIndex = 0;
		}
		Logger::log("piece generated: " + std::to_string(m_pieceBag[m_nextPieceIndex]));
		return m_pieceBag[m_nextPieceIndex++];
	}

	PieceType Generator::holdPiece(PieceType piece)
	{
		PieceType oldPiece = m_heldPiece != None
			? m_heldPiece
			: getNextRandomPiece();
		m_heldPiece = piece;
		return oldPiece;
	}

	void Generator::shuffleBag()
	{
		static std::random_device randomDevice{};
		static std::default_random_engine random{ randomDevice() };

		std::shuffle(std::begin(m_pieceBag), std::end(m_pieceBag), random);
	}
}
