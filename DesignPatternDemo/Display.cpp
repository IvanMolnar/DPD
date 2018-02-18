#include "Display.h"


Display::Display()
{
	_mapAreaInterface = nullptr;
}


Display::~Display()
{
}

std::string Display::getDisplayData()
{
	return _mapAreaInterface->getDisplayData();
}

void Display::init(MapAreaInterface* const mapAreaInterface)
{
	_mapAreaInterface = mapAreaInterface;
}
