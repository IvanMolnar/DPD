#include "MapManager.h"


MapManager::MapManager(const std::shared_ptr<FileSystem>& fileSystem) :
	_fileSystem(fileSystem)
{
}


MapManager::~MapManager()
{
}

void MapManager::loadArea(const std::string& areaName)
{
	std::shared_ptr<MapArea> mapArea = _fileSystem->loadMapArea(areaName);

	_loadedMapAreas.push_back(mapArea);
}

const std::shared_ptr<MapArea> MapManager::getMapAreaFromIndex(const unsigned int mapId)
{
	for (const std::shared_ptr<MapArea>& mapArea : _loadedMapAreas)
	{
		if (mapArea->getMapId() == mapId)
		{
			return mapArea;
		}
	}

	return nullptr;
}

void MapManager::setCurrentMapArea(const unsigned int mapId)
{
	_currentMapArea = getMapAreaFromIndex(mapId);
}
