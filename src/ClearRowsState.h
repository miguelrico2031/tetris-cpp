#pragma once
#include "GameplayState.h"
#include "MovingPiece.h"

class ClearRowsState : public GameplayState
{
public:
	ClearRowsState(GameplayScene& scene);
	virtual void enter() override;
	virtual void update(float dt) override;
private:
	float m_clearRowsTimer;
	int m_columnToClearLeft;
	int m_columnToClearRight;
};
