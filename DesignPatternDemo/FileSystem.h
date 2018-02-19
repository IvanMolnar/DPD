#pragma once

#include "MapArea.h"
#include <memory>

class FileSystem
{
public:
	FileSystem();
	virtual ~FileSystem();

	virtual std::unique_ptr<MapArea> loadMapArea(const std::string& areaName) = 0;
	// load config, etc...
};

