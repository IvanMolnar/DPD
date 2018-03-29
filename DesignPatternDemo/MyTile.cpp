#include "MyTile.h"



MyTile::MyTile(position2d position, TileType tileType) : Tile(tileType)
{
	_displayData._position = position;
}


MyTile::~MyTile()
{
}

MyObjectDisplayData* MyTile::getDisplayData()
{
	return &_displayData;
}