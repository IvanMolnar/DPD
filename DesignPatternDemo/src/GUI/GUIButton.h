#pragma once
#include "GUIElement.h"

class GUIButton : public GUIElement
{
public:
	GUIButton(void* gameLogicInterface);
	~GUIButton();

	void onClick() override;
	void onMouseEnter() override;
	void onMouseLeave() override;

	void update(void* data) override;
};