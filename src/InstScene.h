#pragma once
#ifndef __INST_SCENE__
#define __INST_SCENE__

#include "Scene.h"
#include "Label.h"

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

private:
	Label* m_Label_2;
};

#endif /* defined (__INST_SCENE__) */