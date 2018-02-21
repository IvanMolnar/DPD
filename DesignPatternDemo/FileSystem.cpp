#include "FileSystem.h"


FileSystem::FileSystem()
{
}


FileSystem::~FileSystem()
{
}

std::unique_ptr<MapArea> FileSystem::loadMapArea(const std::string& areaName)
{
	std::unique_ptr<std::string> areaData = readFile(areaName);

//	std::unique_ptr<MapArea> result = std::move(std::make_unique<MapArea>(areaData));

	return std::unique_ptr<MapArea>(new MapArea(std::move(areaData)));
}
