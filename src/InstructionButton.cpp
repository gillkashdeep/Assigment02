#include "InstructionButton.h"
#include "Game.h"

InstructionButton::InstructionButton()

	:Button(
		"../Assets/textures/InstructionButton.png",
		"instButton",
		INST_BUTTON, glm::vec2(440.0f, 300.0f)), m_isClicked(false)
{
}

InstructionButton::~InstructionButton()
{
}

bool InstructionButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{

		if (!m_isClicked)
		{
			TheGame::Instance()->changeSceneState(SceneState::INST_SCENE);
			m_isClicked = true;

		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}



	return false;
}
