#pragma once
#include "Scene.h"
#include "Board.h"
#include "MovingPiece.h"
#include <memory>

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
	std::unique_ptr<Pieces::MovingPiece> m_movingPiece = nullptr;
	float m_movePieceTimer = 0.0f;
	float m_fallPieceTimer = 0.0f;
private:
	void movePieceWithInput();
	void rotatePieceWithInput();
	void fallPiece();
};