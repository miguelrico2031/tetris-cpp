#pragma once
#include "Scene.h"
#include "ButtonManager.h"

class GameOverScene : public Scene
{
public:
	GameOverScene(Game* game);
	virtual void load()  override;
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void unload() override;
private:
	sf::Text m_titleText;
	sf::Text m_scoreText;
	ButtonManager m_buttonManager;
	void saveAndGoToMenu();
};