#pragma once
#include "MyObjectDisplayData.h"

enum class TileType
{
	grass,
	dirt,
	road,
	water
};

class Tile : public MyObjectDisplayData
{
public:
	Tile(position2d position, TileType tileType);
	virtual ~Tile();

	MyObjectDisplayData* getDisplayData();

protected:
	MyObjectDisplayData _displayData;
	TileType _type;

};

