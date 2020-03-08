#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include "Ground.h"
#include "coin.h"
#include "GroundSurface.h"
#include "door.h"

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pGround->draw();
	m_pCoin->draw();
	m_pCoin_1->draw();
	m_pCoin_1->draw();
	m_pCoin_2->draw();
	m_pCoin_3->draw();
	m_pCoin_4->draw();
	m_pGroundSurface->draw();
	m_pDoor->draw();
	m_pLabel->draw();
	m_pLabel1->draw();

}

void Level1Scene::update()
{

	m_pGround->setPosition(glm::vec2(170, 200));
	m_pGroundSurface->setPosition(glm::vec2(170, 350));
	m_pCoin->setPosition(glm::vec2(200, 150));
	m_pCoin_1->setPosition(glm::vec2(50, 150));
	m_pCoin_2->setPosition(glm::vec2(50, 300));
	m_pCoin_3->setPosition(glm::vec2(250, 300));
	m_pCoin_4->setPosition(glm::vec2(450, 300));
	m_pDoor->setPosition(glm::vec2(610, 308));
	

}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
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
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255);
	
	m_pGround= new  Ground();
	m_pGround->setPosition(glm::vec2(150.0f, 150.0f));
	addChild(m_pGround);

	m_pGroundSurface = new  GroundSurface();
	m_pGroundSurface->setPosition(glm::vec2(150.0f, 150.0f));
	addChild(m_pGroundSurface);
	
	m_pCoin= new  coin();
	m_pCoin->setPosition(glm::vec2(200.0f, 250.0f));
	addChild(m_pCoin);

	m_pCoin_1 = new  coin();
	m_pCoin_1->setPosition(glm::vec2(250.0f, 250.0f));
	addChild(m_pCoin_1);


	m_pCoin_2 = new  coin();
	m_pCoin_2->setPosition(glm::vec2(250.0f, 250.0f));
	addChild(m_pCoin_2);


	m_pCoin_3 = new  coin();
	m_pCoin_3->setPosition(glm::vec2(250.0f, 250.0f));
	addChild(m_pCoin_3);


	m_pCoin_4 = new  coin();
	m_pCoin_4->setPosition(glm::vec2(250.0f, 250.0f));
	addChild(m_pCoin_4);

	m_pDoor = new  door();
	m_pDoor->setPosition(glm::vec2(250.0f, 250.0f));
	addChild(m_pDoor);

	SDL_Color black = { 255, 255, 255, 255 };
	m_pLabel = new Label("1", "Consolas", 20, black,
		glm::vec2(550.0f, 80.0f));
	m_pLabel->setParent(this);
	addChild(m_pLabel);

	m_pLabel1 = new Label("Items Collected:", "Consolas", 20, black,
		glm::vec2(440.0f, 80.0f));
	m_pLabel1->setParent(this);
	addChild(m_pLabel);


	


	
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

