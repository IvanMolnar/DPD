#include "Maploader.h"



MapLoader::MapLoader()
{
}


MapLoader::~MapLoader()
{
}

std::unique_ptr<GameObject> MapLoader::createGameObject(GameObjectTypes type)
{
	return GameObjectFactory::getInstance()->createGameObject(type);
}
