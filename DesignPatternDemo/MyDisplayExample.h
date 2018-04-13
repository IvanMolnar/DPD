#pragma once

#include "Display.h"

#include "../../2D_Engine/2D_Engine/2D_Engine.h"

class MyDisplayExample : public Display
{
public:
	MyDisplayExample();
	~MyDisplayExample();

	void start();
	void draw();

private:

	GraphicEngineInterface* _graphicEngineInterface;

	HINSTANCE _dllHandle;

	std::vector<MyObjectDisplayData*> _displayData;
};