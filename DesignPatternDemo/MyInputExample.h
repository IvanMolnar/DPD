#pragma once

#include "Input.h"

class InputInterface;

class MyInputExample : public Input
{
public:
	MyInputExample();
	~MyInputExample();

	void init() override;

private:
	SDL_Event* waitForInput() override;

	InputInterface* _inputInterface;
	HINSTANCE _dllHandle;
};

