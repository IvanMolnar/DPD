#pragma once

#include "GameObjectFactory.h"
#include <list>
#include <memory>

class MapLoader
{
public:
	MapLoader();
	virtual ~MapLoader();

	std::unique_ptr<GameObject> createGameObject();
};

