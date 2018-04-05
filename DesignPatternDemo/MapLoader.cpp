#include "Maploader.h"



MapLoader::MapLoader()
{
}


MapLoader::~MapLoader()
{
}

std::unique_ptr<GameObject> MapLoader::createGameObject(GameObjectType type)
{
	return GameObjectFactory::getInstance()->create(type);
}

std::unique_ptr<Tile> MapLoader::createTile(TileType type)
{
	return TileFactory::getInstance()->create(type);
}