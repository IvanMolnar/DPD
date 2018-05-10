#pragma once

#include "../../2D_Engine/2D_Engine/MyObjectDisplayData.h"

class UIElement : public MyObjectDisplayData
{
public:
	UIElement();
	virtual ~UIElement();

	virtual void onPress() = 0;
	virtual void update(void* data) = 0;
};