#pragma once
#ifndef  __spike__
#define __spike__

#include "DisplayObject.h"

class Spike : public DisplayObject
{
public:

	Spike();
	~Spike();

	void draw() override;
	void update() override;
	void clean() override;


};



#endif