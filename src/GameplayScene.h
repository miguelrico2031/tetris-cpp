#pragma once
#include "Scene.h"
#include "Board.h"
#include "GameplayState.h"
#include <memory>
#include "Level.h"
#include "Generator.h"
#include "HoldPanel.h"
#include "ScorePanel.h"
#include "NextPiecePanel.h"


class GameplayScene : public Scene
{
public:
	GameplayScene(std::string name) : Scene(name) {}
	virtual void load() override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void unload() override;
	inline Board& getBoard() { return m_board; }
	inline const Board& getBoard() const { return m_board; }
	inline Level& getLevel() { return m_level; }
	inline const Level& getLevel() const { return m_level; }
	inline Pieces::Generator& getGenerator() { return m_generator; }
	inline const Pieces::Generator& getGenerator() const { return m_generator; }
	inline HoldPanel& getHoldPanel() { return m_holdPanel; }
	inline const HoldPanel& getHoldPanel() const { return m_holdPanel; }
	inline ScorePanel& getScorePanel() { return m_scorePanel; }
	inline const ScorePanel& getScorePanel() const { return m_scorePanel; }
	inline NextPiecePanel& getNextPiecePanel() { return m_nextPiecePanel; }
	inline const NextPiecePanel& getNextPiecePanel() const { return m_nextPiecePanel; }

	template <typename StateT>
	inline void SetState() { m_currentState = std::make_unique<StateT>(*this); }
private:
	Board m_board;
	Level m_level;
	Pieces::Generator m_generator;
	std::unique_ptr<GameplayState> m_currentState = nullptr;
	HoldPanel m_holdPanel;
	ScorePanel m_scorePanel;
	NextPiecePanel m_nextPiecePanel;
};