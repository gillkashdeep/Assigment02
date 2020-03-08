#include "GroundSurface.h"
#include "Game.h"

GroundSurface::GroundSurface()
{

	TheTextureManager::Instance()->load("../Assets/textures/GroundSurface.png",
		"groundSurface", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("groundSurface");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setType(GameObjectType::GROUNDSURFACE);
	setIsColliding(false);
}

GroundSurface::~GroundSurface()
{
}

void GroundSurface::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("groundSurface", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void GroundSurface::update()
{
}

void GroundSurface::clean()
{
}
