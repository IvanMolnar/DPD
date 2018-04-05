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


	virtual void parse(std::unique_ptr<std::string>& data) = 0;
	

protected:

	virtual std::vector<std::unique_ptr<GameObject>> parseGameObject(std::unique_ptr<std::string>& data) = 0;
	virtual std::vector<std::unique_ptr<Tile>> parseTile(std::unique_ptr<std::string>& data) = 0;

	std::unique_ptr<GameObject> createGameObject(GameObjectType type);
	std::unique_ptr<Tile> createTile(TileType type);
};

