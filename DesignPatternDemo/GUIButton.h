#pragma once
#include "GUIElement.h"

class GUIButton : public GUIElement
{
public:
	GUIButton(void* gameLogicInterface);
	~GUIButton();

	void onPress() override;
	void update(void* data) override;
};