#pragma once

#include "LevelDataInterface.h"
#include <memory>

class Display
{
public:
	Display(MapDataInterface* levelDataInterface);
	virtual ~Display();

	void getDisplayData();

	virtual void start() = 0;
	virtual void draw() = 0;

private:
	std::unique_ptr<MapDataInterface> _levelDataInterface;
};

