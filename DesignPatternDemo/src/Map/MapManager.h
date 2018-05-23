#pragma once

#include "FileSystem\FileSystem.h"
#include <vector>
#include "Display\MyDisplayExample.h"

class MapManager
{
public:
	MapManager(const std::shared_ptr<FileSystem>& fileSystem);
	virtual ~MapManager();


	void loadArea(const std::string& areaName);
	
	void setCurrentMapArea(const unsigned int mapId);
	std::shared_ptr<MapArea> getCurrentMapArea();

private:
	std::shared_ptr<FileSystem> _fileSystem;

	std::vector<std::shared_ptr<MapArea>> _loadedMapAreas;
	std::shared_ptr<MapArea> _currentMapArea;

	std::vector<std::shared_ptr<GameObject>> _loadedGameObjects;
	std::shared_ptr<GameObject> _player;

	const std::shared_ptr<MapArea> getMapAreaFromIndex(const unsigned int mapId);
};

