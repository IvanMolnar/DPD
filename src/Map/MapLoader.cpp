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