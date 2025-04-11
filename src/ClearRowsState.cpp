#include "ClearRowsState.h"
#include "GameplayScene.h"
#include "MovingPieceState.h"
#include "Logger.h"

ClearRowsState::ClearRowsState(GameplayScene& scene)
	: GameplayState(scene)
{
	m_columnToClearRight = (int)CONST::BOARD_WIDTH / 2;
	m_columnToClearLeft = ((int)CONST::BOARD_WIDTH - 1) / 2;
	m_clearRowsTimer = 0.0f;
}

void ClearRowsState::update(float dt)
{
	m_clearRowsTimer += dt;
	if (m_clearRowsTimer < CONST::CLEAR_ROWS_ANIM_STEP_DELAY)
		return;
	
	if (m_columnToClearLeft < 0 || m_columnToClearRight >= CONST::BOARD_WIDTH)
	{
		int points = m_scene.getLevel().getPointsFromClearedRows(m_board.getFullRows().size());
		m_board.moveClearedRowsDown();
		Logger::log("Points: " + std::to_string(points));
		m_scene.SetState<MovingPieceState>();
		return;
	}

	m_clearRowsTimer = 0.0f;
	for (int row : m_board.getFullRows())
	{
		m_board.clearBlock({ m_columnToClearLeft, row });
		m_board.clearBlock({ m_columnToClearRight, row });
	}
	m_columnToClearLeft--;
	m_columnToClearRight++;
	
}
