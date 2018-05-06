#pragma once

#include "GameObjectFactory.h"

#include <vector>
#include <memory>

class MapLoader
{
public:
	MapLoader();
	virtual ~MapLoader();


	virtual std::vector<std::shared_ptr<GameObject>> parseGameObject(std::vector<std::map<std::string, std::string>>& data) = 0;
	

protected:

	

	std::unique_ptr<GameObject> createGameObject(GameObjectType type);
};

