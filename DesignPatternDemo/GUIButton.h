#pragma once
#include "GUIElement.h"

class GUIButton : public GUIElement
{
public:
	GUIButton();
	~GUIButton();

	void onPress() override;
	void update(void* data) override;
};