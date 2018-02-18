#pragma once

#include "Display.h"

class MyDisplayExample : public Display
{
public:
	MyDisplayExample();
	~MyDisplayExample();

	void start();
	void draw();
};

