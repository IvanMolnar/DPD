#pragma once

#include "Input.h"

class MyInputExample : public Input
{
public:
	MyInputExample();
	~MyInputExample();

private:
	unsigned int waitForInput();
};

