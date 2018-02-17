#pragma once

#include "Screen.h"
#include <memory>

class Display
{
public:
	Display();
	virtual ~Display();

	void getDisplayData();
	void setActiveScreen(std::shared_ptr<Screen> activeScreen);

	virtual void start() = 0;
	virtual void draw() = 0;

private:
	std::shared_ptr<Screen> _activeScreen;
};

