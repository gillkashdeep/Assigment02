#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include "Ground.h"
#include "coin.h"
#include "GroundSurface.h"
#include "door.h"
#include "Spike.h"


Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	//m_pGround->draw();
	
	
	if (!isCoinCollected)
		m_pCoin_2->draw();
	
	if (!isCoinCollected_1)
		m_pCoin_3->draw();
	
	if (!isCoinCollected_2)
		m_pCoin_4->draw();

	if (!isCoinCollected_3)
		m_pCoin_1->draw();
	
	if (!isCoinCollected_4)
		m_pCoin->draw();

	m_pSpike->draw();
	m_pSpike_1->draw();
	m_pLabelLife->draw();
	
	//m_pGroundSurface->draw();
	m_pDoor->draw();
	m_pLabel->draw();
	m_pLabel1->draw();
	if(!isPlayerReach)
		m_pPlayer->draw();

	for(Ground* ground:m_pNewGround)
	{
		ground->draw();
	}
}

void Level1Scene::update()
{
	
	for(Ground* ground : m_pNewGround)
	{

		if(m_pPlayer->getPosition().y == 135.25)
		{
			std::cout << "cooooo" << std::endl;
			auto bottomLine = glm::vec2(m_pPlayer->getPosition().x, m_pPlayer->getPosition().y + m_pPlayer->getHeight() / 2 + 40);
			Collision::lineRectCheck(m_pPlayer, bottomLine, ground, ground->getWidth(), ground->getHeight() + 41);
		}
		if (m_pPlayer->getPosition().y != 135)
		{
		
			auto bottomLine = glm::vec2(m_pPlayer->getPosition().x, m_pPlayer->getPosition().y + m_pPlayer->getHeight() / 2 + 20);

			Collision::lineRectCheck(m_pPlayer, bottomLine, ground, ground->getWidth(), ground->getHeight() + 41);
		}
		
		
	}
	
	m_pPlayer->isGrounded=playerIsGrounded();
	m_pPlayer->update();

	//std::cout << "Height" << m_pPlayer->getPosition().y << std::endl;
	
	if(m_pPlayer->getPosition().x < 10)
	{
		//std::cout << "positionset" << std::endl;
		//m_pPlayer->update();
		m_pPlayer->setPosition(glm::vec2(10, m_pPlayer->getPosition().y));
	}

	if(m_pPlayer->getPosition().x > 640)
	{
		m_pPlayer->setPosition(glm::vec2(630, m_pPlayer->getPosition().y));
	}
	if (CollisionManager::AABBCheck(m_pPlayer, m_pCoin) && !isCoinCollected_4)
	{
		isCoinCollected_4 = true;
		TheGame::Instance()->gameScore++;
		TheSoundManager::Instance()->playSound("yay", 0);

	}
	if (CollisionManager::AABBCheck(m_pPlayer, m_pCoin_1) && !isCoinCollected_3)
	{
		isCoinCollected_3 = true;
		TheGame::Instance()->gameScore++;
		TheSoundManager::Instance()->playSound("yay", 0);

	}
	
	if(CollisionManager::AABBCheck(m_pPlayer, m_pCoin_2) && !isCoinCollected)
	{
		isCoinCollected = true;
		TheGame::Instance()->gameScore++;
		TheSoundManager::Instance()->playSound("yay", 0);
		
	}
	if (CollisionManager::AABBCheck(m_pPlayer, m_pCoin_3) && !isCoinCollected_1)
	{
		isCoinCollected_1 = true;
		TheGame::Instance()->gameScore++;
		//m_pLabel->setText("2");
		TheSoundManager::Instance()->playSound("yay", 0);


	}
	if (CollisionManager::AABBCheck(m_pPlayer, m_pCoin_4) && !isCoinCollected_2)
	{
		isCoinCollected_2 = true;
		TheGame::Instance()->gameScore++;
		//m_pLabel->setText("3");
		TheSoundManager::Instance()->playSound("yay", 0);


	}
	if (CollisionManager::AABBCheck(m_pPlayer, m_pDoor))
	{
		TheSoundManager::Instance()->playSound("dr", 0);
		isPlayerReach = true;
		m_pLabel->setText(std::to_string(total));
		
		TheGame::Instance()->changeSceneState(SceneState::END_SCENE);


	}

	if (CollisionManager::AABBCheck(m_pPlayer, m_pSpike))
	{
		TheSoundManager::Instance()->playSound("ls", 0);
		//isPlayerReach = true;
		life--;
		//m_pPlayer->setPosition(glm::vec2(30, 250));
		if (life == 0 && total < 5)
		{
			
			TheGame::Instance()->changeSceneState(SceneState::GAMEOVER);
		}
		if( life < 3 && total == 5)
		{
			TheGame::Instance()->changeSceneState(SceneState::END_SCENE);

		}


	}

	if (CollisionManager::AABBCheck(m_pPlayer, m_pSpike_1))
	{
		TheSoundManager::Instance()->playSound("ls", 0);
		//isPlayerReach = true;
		life--;
		//m_pPlayer->setPosition(glm::vec2(30, 250));

		if (life == 0)
		{
		
			TheGame::Instance()->changeSceneState(SceneState::GAMEOVER);
		}


	}
	std::string temp = "Life:"+std::to_string(life);
	m_pLabelLife->setText(temp);


	
	if(!isPlayerReach)
	{
		m_pLabel->setText(std::to_string(TheGame::Instance()->gameScore));
	}

	//std::cout << "Player Grounded:" << m_pPlayer->isGrounded << std::endl;
	

	
}
bool Level1Scene::playerIsGrounded()
{
	for (Ground* ground : m_pNewGround) {

		if (ground->playerAtGround == true)
		{
			//m_pPlayer->setVelocity(glm::vec2(m_pPlayer->getVelocity().x, 0));
			return true;
		}
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
	while (SDL_PollEvent(&event))
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
				if (m_pPlayer->isGrounded)
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
				m_pPlayer->jumping = false;

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


	m_pSpike = new  Spike();
	m_pSpike->setPosition(glm::vec2(380, 330));
	addChild(m_pSpike);

	m_pSpike_1 = new  Spike();
	m_pSpike_1->setPosition(glm::vec2(150, 330));
	addChild(m_pSpike_1);

	m_pDoor = new  door();
	//m_pDoor->setPosition(glm::vec2(250.0f, 250.0f));
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

	life = 3;
	std::string temp = "Life:" + std::to_string(life);

	m_pLabelLife = new Label(temp, "Consolas", 20, black,
		glm::vec2(505.0f, 100.0f));
	m_pLabelLife->setParent(this);
	addChild(m_pLabelLife);
	

	m_pPlayer = new Player();
	//m_pPlayer->setPosition(glm::vec2(30.0f, 250.0f));
	addChild(m_pPlayer);
	
	m_pPlayer->setPosition(glm::vec2(30, 250));
	//m_pGround->setPosition(glm::vec2(170, 200));
	//m_pGroundSurface->setPosition(glm::vec2(170, 350));

	TheSoundManager::Instance()->load("../Assets/audio/Picked Coin.wav", "yay", SOUND_SFX);
	TheSoundManager::Instance()->load("../Assets/audio/Plug.ogg", "bg", SOUND_SFX);
	TheSoundManager::Instance()->load("../Assets/audio/hit.wav", "ls", SOUND_SFX);

	TheSoundManager::Instance()->load("../Assets/audio/door-01.wav", "dr", SOUND_SFX);

	TheSoundManager::Instance()->playSound("bg", 1);

	m_pDoor->setPosition(glm::vec2(610, 325));

	isCoinCollected = false;
	isCoinCollected_1 = false;
	isCoinCollected_2 = false;
	isPlayerReach = false;

	for(int i=0;i<18;i++)
	{
		m_pNewGround.push_back(new Ground());
	}
	int i = 0;
	bool isPassedRange=false;
	for(Ground* ground : m_pNewGround)
	{
		if(i>640)
		{
			i = 0;
			isPassedRange = true;
		}
		if(isPassedRange)
		{
			ground->setPosition(glm::vec2(i, 190));
		}
		else {
			ground->setPosition(glm::vec2(i, 375));
		}
		i += 56;
	}
	
	TheGame::Instance()->gameScore = 0;
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

