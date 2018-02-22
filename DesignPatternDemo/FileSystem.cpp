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

	_mapLoader->parse(areaData);

	return std::unique_ptr<MapArea>(new MapArea(std::move(areaData)));
}
