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
	unsigned int waitForInput();

	InputInterface* _inputInterface;
	HINSTANCE _dllHandle;
};

