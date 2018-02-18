#pragma once

#include "MapAreaInterface.h"
#include <memory>

class Display
{
public:
	Display();
	virtual ~Display();

	std::string getDisplayData();

	void init(MapAreaInterface* const mapAreaInterface);

	virtual void start() = 0;
	virtual void draw() = 0;

private:
	MapAreaInterface* _mapAreaInterface;
};

