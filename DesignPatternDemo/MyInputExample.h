#pragma once

#include "Input.h"

class MyInputExample : public Input
{
public:
	MyInputExample(screenType st);
	~MyInputExample();

private:
	unsigned int waitForInput();
};

