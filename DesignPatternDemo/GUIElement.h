#pragma once

#include "../../2D_Engine/2D_Engine/MyObjectDisplayData.h"

class GUIElement : public MyObjectDisplayData
{
public:
	GUIElement();
	virtual ~GUIElement();

	virtual void onPress() = 0;
	virtual void update(void* data) = 0;
};