#pragma once
#ifndef  __GroundSurface__
#define __Groundface__

#include "DisplayObject.h"

class GroundSurface : public DisplayObject
{
public:

	GroundSurface();
	~GroundSurface();

	void draw() override;
	void update() override;
	void clean() override;

	bool playerAtGround;

};



#endif