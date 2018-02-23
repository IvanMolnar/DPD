#pragma once

#include "MapLoader.h"

class MyMapLoader : public MapLoader
{
public:
	MyMapLoader();
	~MyMapLoader();

	std::vector<std::unique_ptr<GameObject>> parse(std::unique_ptr<std::string>& data);
};

