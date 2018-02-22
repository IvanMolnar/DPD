#pragma once

#include "MapLoader.h"
#include "MapArea.h"
#include <memory>
#include <iostream>
#include <string>
#include <fstream>

class FileSystem
{
public:
	FileSystem(std::unique_ptr<MapLoader> mapLoader);
	virtual ~FileSystem();


	virtual std::unique_ptr<std::string> readFile(const std::string& fileName) = 0;

	std::unique_ptr<MapArea> loadMapArea(const std::string& areaName);
	// load config, etc...

private:
	std::unique_ptr<MapLoader> _mapLoader;
};

