#include "coin.h"
#include "DisplayObject.h"
#include "TextureManager.h"
#include "Game.h"

//items in the game coins baseclass
coin::coin()
{

	TheTextureManager::Instance()->load("../Assets/textures/coin.png",
		"coin", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("coin");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setType(GameObjectType::COIN);
	setIsColliding(false);

}

coin::~coin()
{
	
}
void coin::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("coin", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);

}
void coin::update()
{
	
}
void coin::clean()
{
	
}
