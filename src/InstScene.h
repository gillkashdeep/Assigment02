#pragma once
#ifndef __INST_SCENE__
#define __INST_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"

class InstScene : public Scene
{
public:
	InstScene();
	~InstScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	glm::vec2 getMousePosition();


private:
	StartButton* m_pStartButton;

	Label* m_Label_2;
	Label* m_Label_3;
	Label* m_Label_4;

	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__INST_SCENE__) */