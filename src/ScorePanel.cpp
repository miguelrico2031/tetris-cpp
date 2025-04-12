#include "ScorePanel.h"

ScorePanel::ScorePanel()
	: Panel(),
	m_scoreTextNumber(CONST::FONT),
	m_levelTextLabel(CONST::FONT),
	m_levelTextNumber(CONST::FONT),
	m_linesTextLabel(CONST::FONT),
	m_linesTextNumber(CONST::FONT)
{
	m_scoreTextLabel.setString(CONST::SCORE_PANEL_TEXT);
	m_scoreTextNumber.setString("0");
	m_levelTextLabel.setString(CONST::SCORE_LEVEL_TEXT);
	m_levelTextNumber.setString("0");
	m_linesTextLabel.setString(CONST::SCORE_LINES_TEXT);
	m_linesTextNumber.setString("0");


	float yPos = 0.0f;
	for (sf::Text* text : m_texts)
	{
		text->setCharacterSize(30);
		auto bounds = text->getLocalBounds();
		text->setPosition(getACenteredPositioninB(CONST::SCORE_PANEL_SIZE, CONST::SCORE_PANEL_POSITION, bounds.size, true));
		text->move({ 0.0f, yPos });
		yPos += CONST::SCORE_PANEL_SIZE.y / m_texts.size();
	}
}

void ScorePanel::draw(sf::RenderWindow& window)
{
	for (sf::Text* text : m_texts)
		window.draw(*text);
}

void ScorePanel::addClearedRows(int clearedRows, int score)
{
	m_lines += clearedRows;
	m_linesTextNumber.setString(std::to_string(m_lines));
	centerTextHorizontally(m_linesTextNumber);

	m_score += score;
	m_scoreTextNumber.setString(std::to_string(m_score));
	centerTextHorizontally(m_scoreTextNumber);
}

void ScorePanel::setLevel(int level)
{
	m_level = level;
	m_levelTextNumber.setString(std::to_string(m_level));
	centerTextHorizontally(m_levelTextNumber);
}

void ScorePanel::centerTextHorizontally(sf::Text& text)
{
	float yPos = text.getPosition().y;
	auto bounds = text.getLocalBounds();
	text.setPosition(getACenteredPositioninB(CONST::SCORE_PANEL_SIZE, CONST::SCORE_PANEL_POSITION, bounds.size, true));
	text.setPosition({ text.getPosition().x, yPos });
}
