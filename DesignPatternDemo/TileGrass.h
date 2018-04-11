#pragma once

#include "Tile.h"

class TileGrass : public Tile
{
public:
	TileGrass(void* gameLogicInterface);
	~TileGrass();

	MyObjectDisplayData* TileGrass::getDisplayData() override;

protected:
	MyObjectDisplayData _displayData;
};

