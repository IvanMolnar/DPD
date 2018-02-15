#pragma once

#include "Input.h"
#include "MapArea.h"

#include <memory>

class Screen : public Input
{
public:
	Screen(screenType st);
	~Screen();

	void loadLevel(std::string fileName);
	resultAction handleInput();

private:
	std::unique_ptr<MapArea> _mapArea;

};

