#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"
#include "Level1Scene.h"

class EndScene : public Scene
{
public:
	EndScene();
	~EndScene();

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
	Label* m_Label2;
	Label* m_Label3;
	std::string state;
	

	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__END_SCENE__) */