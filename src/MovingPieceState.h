#pragma once
#include "GameplayState.h"
#include "MovingPiece.h"
#include <memory>

class MovingPieceState : public GameplayState
{
public:
	MovingPieceState(GameplayScene& scene);
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
private:
	std::unique_ptr<Pieces::MovingPiece> m_movingPiece = nullptr;
	float m_movePieceTimer = 0.0f;
	float m_fallPieceTimer = 0.0f;
	bool m_hasHeld = false;
private:
	void handleMoveInput();
	void handleRotationInput();
	void movePieceSideways(bool right);
	void rotatePiece(bool right);
	void fallPiece();
};