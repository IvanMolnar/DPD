#pragma once

#include "GameObjectFactory.h"
#include "TileFactory.h"

#include <vector>
#include <memory>

class MapLoader
{
public:
	MapLoader();
	virtual ~MapLoader();


	virtual std::vector<std::shared_ptr<GameObject>> parseGameObject(std::unique_ptr<std::string>& data) = 0;
	virtual std::vector<std::shared_ptr<Tile>> parseTile(std::unique_ptr<std::string>& data) = 0;
	

protected:

	

	std::unique_ptr<GameObject> createGameObject(GameObjectType type);
	std::unique_ptr<Tile> createTile(TileType type);
};

