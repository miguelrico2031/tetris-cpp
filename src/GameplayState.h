#pragma once
#include "Board.h"
#include "MovingPiece.h"

class GameplayScene;

class GameplayState
{
public:
	GameplayState(GameplayScene& scene);
	virtual void enter() = 0;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderWindow& window) {}
	virtual ~GameplayState() = default;
protected:
	GameplayScene& m_scene;
	Board& m_board;
};