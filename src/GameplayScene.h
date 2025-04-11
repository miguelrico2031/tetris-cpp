#pragma once
#include "Scene.h"
#include "Board.h"
#include "GameplayState.h"
#include <memory>
#include "Level.h"
#include "Generator.h"


class GameplayScene : public Scene
{
public:
	GameplayScene(std::string name) : Scene(name), m_board(CONST::BOARD_POSITION) {}
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

	template <typename StateT>
	inline void SetState() { m_currentState = std::make_unique<StateT>(*this); }
private:
	Board m_board;
	Level m_level;
	Pieces::Generator m_generator;
	std::unique_ptr<GameplayState> m_currentState = nullptr;
};