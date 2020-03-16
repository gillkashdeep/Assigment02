#pragma once
#ifndef __INST_BUTTON__
#define __INST_BUTTON__

#include "Button.h"

class InstructionButton : public Button
{
public:
	InstructionButton();
	~InstructionButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif 