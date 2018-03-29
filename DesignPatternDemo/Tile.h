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
	Tile(TileType tileType);
	virtual ~Tile();

	virtual MyObjectDisplayData* getDisplayData() = 0;

protected:
	TileType _type;

};

