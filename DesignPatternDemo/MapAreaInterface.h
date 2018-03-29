#pragma once

#include "Global.h"
#include <vector>
#include "MyObjectDisplayData.h"

class MapAreaInterface
{
public:
	MapAreaInterface() {};
	~MapAreaInterface() {};

	virtual std::vector<MyObjectDisplayData*> getDisplayData() = 0;
};
