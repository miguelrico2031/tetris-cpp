#pragma once
#include "Scene.h"
#include "GameplayScene.h"
#include "ButtonManager.h"
#include "Game.h"

class MenuScene : public Scene
{
public:
	MenuScene(Game* game);
	virtual void load()  override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void unload() override;
private:
	ButtonManager m_buttonManager;
	sf::Text m_titleText;
	sf::Text m_highscoreText;
	int m_selectedLevelIndex = 0;
	sf::Text* m_levelButtonText = nullptr;
private:
	void startGameplay();
	void toggleLevel();
};