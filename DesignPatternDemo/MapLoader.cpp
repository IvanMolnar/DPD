#include "Maploader.h"



MapLoader::MapLoader()
{
}


MapLoader::~MapLoader()
{
}

std::unique_ptr<GameObject> MapLoader::createGameObject()
{
//	GameObjectFactory::createGameObject()
	return std::unique_ptr<GameObject>();
}
