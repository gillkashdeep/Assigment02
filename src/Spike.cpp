#include "Spike.h"
#include "TextureManager.h"
#include "Game.h"

//hurdles in the way created on Level1
Spike::Spike()
{
	TheTextureManager::Instance()->load("../Assets/textures/spike.png",
		"spike", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("spike");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setType(GameObjectType::COIN);
	setIsColliding(false);
}

Spike::~Spike()
{
}

void Spike::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("spike", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Spike::update()
{
}

void Spike::clean()
{
}
