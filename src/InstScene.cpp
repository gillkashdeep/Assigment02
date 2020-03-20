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
	m_Label_3->draw();
	m_Label_4->draw();
	m_pStartButton->draw();
}

void InstScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
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
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				break;
			}
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
	SDL_Color white = { 0, 0, 0, 0 };

	
	m_Label_2 = new Label("INSTRUCTIONS", "OpenSans-Semibold", 40, white, glm::vec2(300.0f, 100.0f));
	m_Label_2->setParent(this);
	addChild(m_Label_2);
	m_Label_3 = new Label("COMMON CONTROLS - A W S D", "OpenSans-Regular", 30, white, glm::vec2(300.0f, 170.0f));
	m_Label_3->setParent(this);
	addChild(m_Label_3);
	m_Label_4 = new Label("Collect coins-go to the door-complete the level", "OpenSans-Regular", 20, white, glm::vec2(300.0f, 230.0f));
	m_Label_4->setParent(this);
	addChild(m_Label_4);
	m_pStartButton = new StartButton();
	m_pStartButton->setPosition(glm::vec2(300.0f,300.0f));
	addChild(m_pStartButton);

}

