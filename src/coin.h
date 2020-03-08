#pragma once
#ifndef  __coin__
#define __coin__

#include "DisplayObject.h"

class coin : public DisplayObject
{
public:

	coin();
	~coin();

	void draw() override;
	void update() override;
	void clean() override;


};



#endif