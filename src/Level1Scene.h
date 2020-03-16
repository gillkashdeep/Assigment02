#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Ground.h"
#include <SDL.h>
#include "Label.h"
#include "Player.h"
#include "GroundSurface.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	bool playerIsGrounded();
	// getters
	glm::vec2 getMousePosition();

private:
	// game objects

	Ground* m_pGround;
	GroundSurface* m_pGroundSurface;
	DisplayObject* m_pDoor;
	SDL_Renderer* renderer;
	SDL_Window* window;
	
	DisplayObject* m_pCoin;
	DisplayObject* m_pCoin_1;
	DisplayObject* m_pCoin_2;
	DisplayObject* m_pCoin_3;
	DisplayObject* m_pCoin_4;
	Label* m_pLabel;
	Label* m_pLabel1;
	Player* m_pPlayer;

	bool isCoinCollected;
	bool isCoinCollected_1;
	bool isCoinCollected_2;
	bool isPlayerReach;

	// private data member
	glm::vec2 m_mousePosition;
	
	
};

#endif 
