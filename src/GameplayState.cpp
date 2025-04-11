#include "GameplayState.h"
#include "GameplayScene.h"

GameplayState::GameplayState(GameplayScene& scene)
	: m_scene(scene),
	m_board(scene.getBoard())
{}