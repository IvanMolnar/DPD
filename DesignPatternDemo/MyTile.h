#pragma once

#include "Tile.h"

class MyTile : public Tile
{
public:
	MyTile(position2d position, TileType tileType);
	~MyTile();

	MyObjectDisplayData* MyTile::getDisplayData() override;

protected:
	MyObjectDisplayData _displayData;
};

