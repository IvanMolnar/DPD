#pragma once

#include "Input.h"

class InputCommand : public Input
{
public:
	InputCommand();
	~InputCommand();

	unsigned int waitForInput();
};

