#include "Generator.h"
#include <algorithm>
#include <random>
#include "Logger.h"

namespace Pieces
{
	PieceType Generator::getNextRandomPiece()
	{
		PieceType piece = m_next3Pieces.front();
		m_next3Pieces.pop();
		if (m_nextPieceIndex >= m_pieceBag.size())
		{
			shuffleBag();
		}
		else
		{
			m_next3Pieces.push(m_pieceBag[m_nextPieceIndex++]);
		}
		Logger::log("piece generated: " + std::to_string(piece));
		return piece;
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
		m_nextPieceIndex = 0;

		while (m_next3Pieces.size() < 3)
		{
			m_next3Pieces.push(m_pieceBag[m_nextPieceIndex++]);
		}
	}
}
