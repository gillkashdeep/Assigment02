#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include "Ground.h"
#include "coin.h"
#include "GroundSurface.h"
#include "door.h"
int one, two, three, four, five,total;

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
	
	if (!isCoinCollected)
		m_pCoin_2->draw();
	
	if (!isCoinCollected_1)
		m_pCoin_3->draw();
	
	if (!isCoinCollected_2)
		m_pCoin_4->draw();
	
	m_pGroundSurface->draw();
	m_pDoor->draw();
	m_pLabel->draw();
	m_pLabel1->draw();
	if(!isPlayerReach)
		m_pPlayer->draw();
}

void Level1Scene::update()
{
	auto bottomLine = glm::vec2(m_pPlayer->getPosition().x, m_pPlayer->getPosition().y + m_pPlayer->getHeight() / 2 + 22);
	Collision::lineRectCheck(m_pPlayer, bottomLine,m_pGround, m_pGround->getWidth(), m_pGround->getHeight());
	Collision::lineRectCheck(m_pPlayer, bottomLine, m_pGroundSurface, m_pGroundSurface->getWidth(), m_pGroundSurface->getHeight());
	
	playerIsGrounded();
	m_pPlayer->update();
	//std::cout << m_pPlayer->isGrounded << std::endl;

	if(m_pPlayer->getPosition().x < 10)
	{
		//std::cout << "positionset" << std::endl;
		m_pPlayer->update();
	}
	if(CollisionManager::AABBCheck(m_pPlayer, m_pCoin_2))
	{
		one = 1;
		isCoinCollected = true;
		TheSoundManager::Instance()->playSound("yay", 0);
		
	}
	if (CollisionManager::AABBCheck(m_pPlayer, m_pCoin_3))
	{
		isCoinCollected_1 = true;
		//m_pLabel->setText("2");
		two = 1;
		TheSoundManager::Instance()->playSound("yay", 0);


	}
	if (CollisionManager::AABBCheck(m_pPlayer, m_pCoin_4))
	{
		isCoinCollected_2 = true;
		//m_pLabel->setText("3");
		three = 1;
		TheSoundManager::Instance()->playSound("yay", 0);


	}
	if (CollisionManager::AABBCheck(m_pPlayer, m_pDoor))
	{
		
		isPlayerReach = true;
		one = 0;
		two = 0;
		three = 0;
		total = one+two+three;
		m_pLabel->setText(std::to_string(total));

		TheGame::Instance()->changeSceneState(SceneState::END_SCENE);


	}
	total = one + two + three + four + five;

	
	if(!isPlayerReach)
	{
		m_pLabel->setText(std::to_string(total));
	}
	
	

	
}
bool Level1Scene::playerIsGrounded()
{
	if(m_pGround->playerAtGround == true)
	{
		m_pPlayer->isGrounded = true;
		m_pPlayer->isGroundSurfaced = false;
	}
	if(m_pGroundSurface->playerAtGround == true)
	{
		m_pPlayer->isGrounded = false;
		m_pPlayer->isGroundSurfaced = true;
	}

	return false;
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
				if (m_pPlayer->isGroundSurfaced)
				{
					m_pPlayer->jump();

				}
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:
				m_pPlayer->move(LEFT);

				break;
			case SDLK_d:
				m_pPlayer->move(RIGHT);
				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				//m_pPlayer->stopJump();
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:
				m_pPlayer->setVelocity(glm::vec2(0, m_pPlayer->getVelocity().y));

				break;
			case SDLK_d:
				m_pPlayer->setVelocity(glm::vec2(0, m_pPlayer->getVelocity().y));

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
	m_pCoin->setPosition(glm::vec2(200, 150));
	addChild(m_pCoin);

	m_pCoin_1 = new  coin();
	m_pCoin_1->setPosition(glm::vec2(50, 150));
	addChild(m_pCoin_1);


	m_pCoin_2 = new  coin();
	m_pCoin_2->setPosition(glm::vec2(90, 300));
	addChild(m_pCoin_2);


	m_pCoin_3 = new  coin();
	m_pCoin_3->setPosition(glm::vec2(250, 300));
	addChild(m_pCoin_3);


	m_pCoin_4 = new  coin();
	m_pCoin_4->setPosition(glm::vec2(450, 300));
	addChild(m_pCoin_4);

	m_pDoor = new  door();
	m_pDoor->setPosition(glm::vec2(250.0f, 250.0f));
	addChild(m_pDoor);

	SDL_Color black = { 255, 255, 255, 255 };
	m_pLabel = new Label("0", "Consolas", 20, black,
		glm::vec2(550.0f, 80.0f));
	m_pLabel->setParent(this);
	addChild(m_pLabel);

	m_pLabel1 = new Label("Coins Collected:", "Consolas", 20, black,
		glm::vec2(440.0f, 80.0f));
	m_pLabel1->setParent(this);
	addChild(m_pLabel);

	m_pPlayer = new Player();
	//m_pPlayer->setPosition(glm::vec2(30.0f, 250.0f));
	addChild(m_pPlayer);
	
	m_pPlayer->setPosition(glm::vec2(30, 270));
	m_pGround->setPosition(glm::vec2(170, 200));
	m_pGroundSurface->setPosition(glm::vec2(170, 350));

	TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);
	TheSoundManager::Instance()->load("../Assets/audio/Interstellar Odyssey.ogg", "bg", SOUND_SFX);
	TheSoundManager::Instance()->playSound("bg", 1);

	m_pDoor->setPosition(glm::vec2(610, 308));

	isCoinCollected = false;
	isCoinCollected_1 = false;
	isCoinCollected_2 = false;
	isPlayerReach = false;

	
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

