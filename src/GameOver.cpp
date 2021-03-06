#include "GameOver.h"
#include "Game.h"

// when all the lifes lost 
GameOver::GameOver()
{
	GameOver::start();
}


GameOver::~GameOver()
{
}

void GameOver::draw()
{
	m_Label->draw();
	m_pStartButton->draw();
}

void GameOver::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
}

void GameOver::clean()
{
	delete m_Label;
	removeAllChildren();
}

void GameOver::handleEvents()
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

void GameOver::start()
{
	SDL_Color white = { 0, 0, 0, 0 };
	m_Label = new Label("GAME OVER", "OpenSans-Semibold", 80, white, glm::vec2(300.0f, 50.0f));
	m_Label->setParent(this);
	addChild(m_Label);

	
	m_pStartButton = new StartButton();
	m_pStartButton->setPosition(glm::vec2(300.0f, 300.0f));
	addChild(m_pStartButton);
}


