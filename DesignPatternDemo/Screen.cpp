#include "Screen.h"



Screen::Screen(screenType st) :
	Input(st)
{
	_mapArea = std::unique_ptr<MapArea>(new MapArea());
}


Screen::~Screen()
{
}

void Screen::loadLevel(std::string fileName)
{
	_mapArea->loadLevel(fileName);
}

resultAction Screen::handleInput()
{
	return Input::handleInput();
}