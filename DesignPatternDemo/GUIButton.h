#pragma once
#include "UIElement.h"

class GUIButton : public UIElement
{
public:
	GUIButton();
	~GUIButton();

	void onPress() override;
	void update(void* data) override;
};