#include "Display.h"


Display::Display()
{
}


Display::~Display()
{
}

void Display::getDisplayData()
{
//	return _activeScreen->getLevelDisplayData();
}

void Display::setActiveScreen(std::shared_ptr<Screen> activeScreen)
{
	_activeScreen = activeScreen;
}
