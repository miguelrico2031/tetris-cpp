#pragma once
#include "Scene.h"
#include "MovingPiece.h"
#include "Board.h"

class GameplayScene : public Scene
{
public:
	GameplayScene(std::string name) : Scene(name), m_board(CONST::BOARD_POSITION) {}

	virtual void load() override;

	virtual void update(float dt) override;

	virtual void render(sf::RenderWindow& window) override;

	virtual void unload() override;

private:
	Pieces::Board m_board;
	Pieces::MovingPiece* m_movingPiece = nullptr;

};