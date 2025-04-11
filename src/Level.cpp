#include "Level.h"
#include "const.h"
#include <algorithm>
#include "Logger.h"

Level::Level(int startLevel)
	: m_currentLevel(startLevel)
{}


float Level::getFallPeriod() const
{
	int index = std::min(m_currentLevel, (int)CONST::LEVEL_FALL_PERIODS.size() - 1);
	return CONST::LEVEL_FALL_PERIODS[index];
}


int Level::getPointsFromClearedRows(int rowsCleared)
{
	assert(rowsCleared > 0 && rowsCleared <= 4, "Rows cleared must be between 1 and 4");
	m_clearedRows += rowsCleared;
	int points = CONST::LEVEL_POINTS_PER_ROW[rowsCleared] * (m_currentLevel + 1);

	int targetLevel = m_clearedRows / 10;
	if (targetLevel > m_currentLevel)
	{
		m_currentLevel = targetLevel;
		Logger::log("Level up! New level: " + std::to_string(m_currentLevel));
	}

	return points;
}

