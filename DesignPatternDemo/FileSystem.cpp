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
}
