#include "FileSystem.h"


FileSystem::FileSystem(std::unique_ptr<MapLoader> mapLoader) :
	_mapLoader(std::move(mapLoader))
{
}


FileSystem::~FileSystem()
{
}

std::unique_ptr<MapArea> FileSystem::loadMapArea(const std::string& areaName)
{
	std::unique_ptr<std::string> areaData = readFile(areaName);

	std::unique_ptr<MapArea> newMapArea = std::unique_ptr<MapArea>(new MapArea(std::move(areaData), _mapLoader.get()));

	newMapArea->loadMapData();

	return newMapArea;
}
