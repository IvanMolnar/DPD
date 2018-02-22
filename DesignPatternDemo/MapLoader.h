#pragma once

#include "GameObjectFactory.h"

#include <vector>
#include <memory>

class MapLoader
{
public:
	MapLoader(std::shared_ptr<GameObjectFactory> gameObjectFactory);
	virtual ~MapLoader();

	virtual std::vector<std::unique_ptr<GameObject>> parse(std::unique_ptr<std::string>& data) = 0;

protected:
	std::unique_ptr<GameObject> createGameObject(GameObjectTypes type);
	std::shared_ptr<GameObjectFactory> _gameObjectFactory;
};

