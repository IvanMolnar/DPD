#pragma once

#include "MapLoader.h"

class MyMapLoader : public MapLoader
{
public:
	MyMapLoader(std::shared_ptr<GameObjectFactory> gameObjectFactory);
	~MyMapLoader();

	std::vector<std::unique_ptr<GameObject>> parse(std::unique_ptr<std::string>& data);
};

