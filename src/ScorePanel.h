#pragma once
#include "Panel.h"
#include <array>

class ScorePanel : public Panel
{
public:
	ScorePanel();
	virtual void draw(sf::RenderWindow& window) override;
	void addClearedRows(int clearedRows, int score);
	void setLevel(int level);
private:
	int m_score = 0;
	int m_level = 0;
	int m_lines = 0;
	sf::Text& m_scoreTextLabel = m_text;
	sf::Text m_scoreTextNumber;
	sf::Text m_levelTextLabel;
	sf::Text m_levelTextNumber;
	sf::Text m_linesTextLabel;
	sf::Text m_linesTextNumber;
	std::array<sf::Text*, 6> m_texts =
	{
		&m_scoreTextLabel, &m_scoreTextNumber,
		&m_levelTextLabel, &m_levelTextNumber,
		&m_linesTextLabel, &m_linesTextNumber
	};
private:
	void centerTextHorizontally(sf::Text& text);
};