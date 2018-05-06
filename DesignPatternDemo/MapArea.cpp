#include "MapArea.h"
#include <iostream>
#include <fstream>

#include <algorithm>
#include "IniParser.h"

MapArea::MapArea(std::unique_ptr<std::string> mapLoadData, MapLoader* mapLoader) :
	_mapId(0),
	_mapLoadData(std::move(mapLoadData)),
	_mapLoader(mapLoader)
{
}

MapArea::~MapArea()
{
}

std::vector<std::map<std::string, std::string>> MapArea::generateChunks()
{
	std::vector<std::map<std::string, std::string>> result;

	std::vector<chunk> mapInfo;

	IniParser iniParser;

	iniParser.setData(*_mapLoadData.get());

	chunk dataChunk = iniParser.getNextChunk();

	while (dataChunk.sectionName.size() > 0)
	{
		mapInfo.push_back(dataChunk);
		dataChunk = iniParser.getNextChunk();
	}

	iniParser.open("ObjectDatabase.ini");
	std::vector<chunk> ObjectDatabase;

	dataChunk = iniParser.getNextChunk();

	while (dataChunk.sectionName.size() > 0)
	{
		ObjectDatabase.push_back(dataChunk);
		dataChunk = iniParser.getNextChunk();
	}

	for (auto& chunk : mapInfo)
	{
		for (auto& chunkDatabase : ObjectDatabase)
		{
			if (chunk.sectionName == chunkDatabase.sectionName)
			{
				std::map<std::string, std::string> objectForLoading;

				objectForLoading = chunkDatabase.data;

				for (auto& map : chunk.data)
				{
					objectForLoading[map.first] = map.second;
				}

				result.push_back(objectForLoading);

				break;
			}
		}
	}

	return result;
}

void MapArea::loadMapData()
{
	std::vector<std::map<std::string, std::string>> dataChunks = generateChunks();

	auto loadedObjects = _mapLoader->parseGameObject(dataChunks);

	for (auto& object : loadedObjects)
	{
		if (object->getType() == GameObjectType::Tile)
		{
			_mapData[std::move(object)] = std::list<std::shared_ptr<GameObject>>();
		}
		else if (object->getType() == GameObjectType::Player)
		{
			_player = object;
		}
		
	}

	for (auto& object : loadedObjects)
	{
		if (object)
		{
			for (auto& data : _mapData)
			{
				if (data.first->_position.x == object->_position.x && data.first->_position.y == object->_position.y)
				{
					data.second.push_back(object);
				}
			}
		}
	}
}

std::shared_ptr<GameObject> MapArea::getTileFromDirection(GameObject* const gameObject, Directions direction)
{
	int tileOffsetX = 0;
	int tileOffsetY = 0;

	switch (direction)
	{
	case Directions::North:
		--tileOffsetY;
		break;
	case Directions::South:
		++tileOffsetY;
		break;
	case Directions::East:
		++tileOffsetX;
		break;
	case Directions::West:
		--tileOffsetX;
		break;
	default:
		return nullptr;
	}


	std::shared_ptr<GameObject> tile = getTileFromObject(gameObject);

	if (!tile)
	{
		return nullptr;
	}

	position2d targetedPosition(tile->_position.x + tileOffsetX, tile->_position.y + tileOffsetY);

	std::shared_ptr<GameObject> tileFromPosition = getTileFromPosition(targetedPosition);

	return tileFromPosition;
}

std::shared_ptr<GameObject> MapArea::getTileFromObject(GameObject* const gameObject)
{
	for (auto& data : _mapData)
	{
		std::list<std::shared_ptr<GameObject>> gameObjectList = data.second;

		for (auto& object : gameObjectList)
		{
			if (object.get() == gameObject)
			{
				return data.first;
			}
		}

	}

	return nullptr;
}

std::shared_ptr<GameObject> MapArea::getTileFromPosition(position2d position)
{
	for (auto& data : _mapData)
	{
		if (data.first->_position.x == position.x && data.first->_position.y == position.y)
		{
			return data.first;
		}
	}

	return nullptr;
}

std::shared_ptr<GameObject> MapArea::getPlayer()
{
	return _player;
}

bool MapArea::canMove(GameObject* const gameObject, Directions direction)
{
	bool result = false;

	std::shared_ptr<GameObject> tile = getTileFromDirection(gameObject, direction);

	if (tile)
	{
		std::list<std::shared_ptr<GameObject>> objects = _mapData[tile];
		
		if (objects.size() == 0)
		{
			result = true;
		}
	}

	return result;
}

void MapArea::move(GameObject* const gameObject, Directions direction)
{
	std::shared_ptr<GameObject> tile = getTileFromDirection(gameObject, direction);

	if (!tile)
	{
		return;
	}

	for (auto& data : _mapData)
	{
		for (auto& object : data.second)
		{
			if (object.get() == gameObject)
			{
				object->_position.x = tile->_position.x;
				object->_position.y = tile->_position.y;
				_mapData[tile].push_back(object);
				data.second.remove(object);
				return;
			}
		}
	}

}

unsigned int MapArea::getMapId()
{
	return _mapId;
}

std::vector<MyObjectDisplayData*> MapArea::getDisplayData()
{
	std::vector<MyObjectDisplayData*> result;

	for (auto& data : _mapData)
	{
		for (auto& object : data.second)
		{
			result.push_back(object.get());
		}

		result.push_back(data.first.get());
	}

	return result;
}

GameObject* MapArea::getObjectNextTo(GameObject* const gameObject, Directions direction)
{
	GameObject* result = nullptr;

	

	return result;
}

std::list<GameObject*> MapArea::getGameObjectByType(GameObjectType gameObjectType)
{
	std::list<GameObject*> result;


	return result;
}

std::list<GameObject*> MapArea::getGameObjects()
{
	std::list<GameObject*> result;


	return result;
}

void MapArea::remove(std::shared_ptr<GameObject> gameObject)
{

}
