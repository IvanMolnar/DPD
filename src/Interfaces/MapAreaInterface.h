#pragma once

#include "Utility\Global.h"
#include <vector>
#include "../../../../2D_Engine/2D_Engine/MyObjectDisplayData.h"

class MapAreaInterface
{
public:
	MapAreaInterface() {};
	~MapAreaInterface() {};

	virtual std::vector<MyObjectDisplayData*> getDisplayData() = 0;
};
