#include "MapArea.h"
#include <iostream>
#include <fstream>

#include <algorithm>

MapArea::MapArea(std::unique_ptr<std::string> mapLoadData, MapLoader* mapLoader) :
	_mapId(0),
	_mapLoadData(std::move(mapLoadData)),
	_mapLoader(mapLoader)
{
}

MapArea::~MapArea()
{
}

void MapArea::loadMapData()
{
	auto loadedTiles = _mapLoader->parseTile(*(_mapLoadData.get()));

	for (auto& tile : loadedTiles)
	{
		_mapData[std::move(tile)] = std::list<std::shared_ptr<GameObject>>();
	}
	/*
	//test
	int row = 0;
	int column = 0;
	for (int i = 0; i < 20; i++, column++)
	{
		std::shared_ptr<Tile> newTile = TileFactory::getInstance()->create(TileType::Grass);
		newTile->_position.x = column;
		newTile->_position.y = row;

//		_graphicEngineInterface->loadTexture(newTile.get());

		_mapData[newTile] = std::list<std::shared_ptr<GameObject>>();

		if (column == 4)
		{
			column = -1;
			++row;
		}
	}*/

	//add player

	auto loadedObjects =_mapLoader->parseGameObject(*(_mapLoadData.get()));

	for (auto& object : loadedObjects)
	{
		for (auto& data : _mapData)
		{
			if (data.first->_position.x == object->_position.x && data.first->_position.y == object->_position.y)
			{
				if (object->_position.x == 0 && object->_position.y == 0)
				{
					_player = object;
				}
				
				data.second.push_back(object);
		//		break;
			}
		}
	}
	/*
	for (auto& data : _mapData)
	{
		if (data.first->_position.x == 0 && data.first->_position.y == 0)
		{
			_player = GameObjectFactory::getInstance()->create(GameObjectType::Player);
	//		_graphicEngineInterface->loadTexture(_player.get());
			data.second.push_back(_player);
			break;
		}
	}*/

}

std::shared_ptr<Tile> MapArea::getTileFromDirection(GameObject* const gameObject, Directions direction)
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


	std::shared_ptr<Tile> tile = getTileFromObject(gameObject);

	if (!tile)
	{
		return nullptr;
	}

	position2d targetedPosition(tile->_position.x + tileOffsetX, tile->_position.y + tileOffsetY);

	std::shared_ptr<Tile> tileFromPosition = getTileFromPosition(targetedPosition);

	return tileFromPosition;
}

std::shared_ptr<Tile> MapArea::getTileFromObject(GameObject* const gameObject)
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

std::shared_ptr<Tile> MapArea::getTileFromPosition(position2d position)
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

	std::shared_ptr<Tile> tile = getTileFromDirection(gameObject, direction);

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
	std::shared_ptr<Tile> tile = getTileFromDirection(gameObject, direction);

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
