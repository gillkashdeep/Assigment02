#pragma once
#ifndef  __door__
#define __Groundface__

#include "DisplayObject.h"

class door : public DisplayObject
{
public:

	door();
	~door();

	void draw() override;
	void update() override;
	void clean() override;

	bool playerAtGround;

};



#endif