#pragma once

#include "MapLoader.h"

class MyMapLoader : public MapLoader
{
public:
	MyMapLoader();
	~MyMapLoader();

	std::vector<std::shared_ptr<GameObject>> parseGameObject(std::vector<std::map<std::string, std::string>>& data) override;
};

