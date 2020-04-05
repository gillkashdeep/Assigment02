#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
{
}

void EndScene::draw()
{
	m_Label->draw();
	m_Label2->draw();
	m_Label3->draw();
	m_pStartButton->draw();
}

void EndScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
	if (TheGame::Instance()->gameScore < 5)
	{

		m_Label3->setText("You Loss!");
	}

	if (TheGame::Instance()->gameScore == 5)
	{
		m_Label3->setText("You Win!");
		
	}

}

void EndScene::clean()
{
	delete m_Label;
	removeAllChildren();
}

void EndScene::handleEvents()
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
			}
			break;
		default:
			break;
		}
	}
}

void EndScene::start()
{
	SDL_Color white = { 0, 0, 0, 0 };
	m_Label = new Label("PLAY AGAIN", "OpenSans-Semibold", 50, white, glm::vec2(300.0f, 50.0f));
	m_Label->setParent(this);
	addChild(m_Label);

	SDL_Color yellow = { 0, 0, 0, 0 };
	
	std::string temp = "Your Score:" + std::to_string(TheGame::Instance()->gameScore);
	
	m_Label2 = new Label(temp, "OpenSans-Semibold", 50, white, glm::vec2(300.0f, 150.0f));
	m_Label2->setParent(this);
	addChild(m_Label2);


	
	

	m_Label3 = new Label("State", "OpenSans-Semibold", 50, white, glm::vec2(300.0f, 100.0f));
	m_Label3->setParent(this);
	addChild(m_Label3);
	
	m_pStartButton = new StartButton();
	m_pStartButton->setPosition(glm::vec2(300.0f, 300.0f));
	addChild(m_pStartButton);
	
}
