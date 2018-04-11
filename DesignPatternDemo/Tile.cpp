#include "Tile.h"


Tile::Tile(TileType tileType) : _type(tileType)
{
	_drawLayer = 0;
}

Tile::~Tile()
{
}
