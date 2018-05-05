#pragma once

#include "MapLoader.h"

class MyMapLoader : public MapLoader
{
public:
	MyMapLoader();
	~MyMapLoader();

	std::vector<std::shared_ptr<GameObject>> parseGameObject(std::string& data) override;
	std::vector<std::shared_ptr<Tile>> parseTile(std::string& data) override;
};

