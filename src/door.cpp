#include "door.h"
#include "Game.h"

door::door()
{
	TheTextureManager::Instance()->load("../Assets/textures/door.png",
		"door", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("door");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setType(GameObjectType::GROUNDSURFACE);
	setIsColliding(false);
}

door::~door()
{
}

void door::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("door", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void door::update()
{
}

void door::clean()
{
}
