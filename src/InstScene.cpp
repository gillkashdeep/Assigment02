#include "InstScene.h"
#include "InstScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

InstScene::InstScene()
{
	InstScene::start();
}

InstScene::~InstScene()
{
}

void InstScene::draw()
{
	m_Label_2->draw();
}

void InstScene::update()
{
}

void InstScene::clean()
{
	
}

void InstScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_3:
				TheGame::Instance()->changeSceneState(SceneState::INST_SCENE);
				break;
			}
			break;
		default:
			break;
		}
	}
}

void InstScene::start()
{
	SDL_Color blue = { 0, 0, 255, 255 };
	m_Label_2 = new Label("INST SCENE", "Dock51", 80, blue, glm::vec2(400.0f, 40.0f));
	m_Label_2->setParent(this);
	addChild(m_Label_2);
}
