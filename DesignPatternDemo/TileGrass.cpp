#include "TileGrass.h"



TileGrass::TileGrass(void* gameLogicInterface) : Tile(TileType::Grass)
{
	_displayData._position = position2d(0, 0);
}


TileGrass::~TileGrass()
{
}

MyObjectDisplayData* TileGrass::getDisplayData()
{
	return &_displayData;
}