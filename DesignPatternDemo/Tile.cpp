#include "Tile.h"


Tile::Tile(position2d position, TileType tileType) : _type(tileType)
{
	_displayData._position = position;
}

Tile::~Tile()
{
}

MyObjectDisplayData* Tile::getDisplayData()
{
	return &_displayData;
}
