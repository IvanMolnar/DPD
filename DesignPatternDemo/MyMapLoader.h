#pragma once

#include "MapLoader.h"

class MyMapLoader : public MapLoader
{
public:
	MyMapLoader();
	~MyMapLoader();

	void parse(std::unique_ptr<std::string>& data) override;

	std::vector<std::unique_ptr<GameObject>> parseGameObject(std::unique_ptr<std::string>& data) override;
	std::vector<std::unique_ptr<Tile>> parseTile(std::unique_ptr<std::string>& data) override;
};

