#pragma once
#ifndef __GAMEOVER_SCENE__
#define __GAMEOVER_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"
#include "Level1Scene.h"

class GameOver : public Scene
{
public:
	GameOver();
	~GameOver();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	glm::vec2 getMousePosition();


private:
	StartButton* m_pStartButton;
	Label* m_Label;



	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__END_SCENE__) */