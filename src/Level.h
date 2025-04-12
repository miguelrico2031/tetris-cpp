#pragma once

class Level
{
public:
	Level(int startLevel = 0);
	float getFallPeriod() const;
	int getPointsFromClearedRows(int rowsCleared);
	inline int getCurrentLevel() const { return m_currentLevel; }
private:
	int m_currentLevel = 0;
	int m_clearedRows = 0;
};