#pragma once
#include "UIElement.h"

class UIButton : public UIElement
{
public:
	UIButton();
	~UIButton();

	void onPress() override;
	void update(void* data) override;
};