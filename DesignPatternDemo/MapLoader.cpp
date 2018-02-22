#include "Maploader.h"



MapLoader::MapLoader(std::shared_ptr<GameObjectFactory> gameObjectFactory)
{
	_gameObjectFactory = gameObjectFactory;
}


MapLoader::~MapLoader()
{
}

std::unique_ptr<GameObject> MapLoader::createGameObject(GameObjectTypes type)
{
	return _gameObjectFactory->createGameObject(type);
}
