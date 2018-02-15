#pragma once

class MapDataInterface
{
public:
	MapDataInterface() {};
	~MapDataInterface() {};

	virtual void getLevelDisplayData() = 0;
};

