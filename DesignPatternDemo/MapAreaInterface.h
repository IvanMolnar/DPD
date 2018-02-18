#pragma once

#include "Global.h"

class MapAreaInterface
{
public:
	MapAreaInterface() {};
	~MapAreaInterface() {};

	virtual std::string getDisplayData() = 0;
};

