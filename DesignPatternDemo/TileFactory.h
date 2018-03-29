#pragma once

#include "GenericFactory.h"
#include "Tile.h"

class TileFactory : public GenericFactory<TileType, Tile>
{

};
