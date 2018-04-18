#include "Tile.h"


Tile::Tile(TileType tileType) : _type(tileType)
{
	_drawLayer = DrawingLayer::Floor;
}

Tile::~Tile()
{
}
