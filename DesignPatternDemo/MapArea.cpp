#include "MapArea.h"
#include <iostream>
#include <fstream>

#include <algorithm>

MapArea::MapArea(std::unique_ptr<std::string> mapLoadData, MapLoader* mapLoader) :
	_mapId(0),
	_mapLoadData(std::move(mapLoadData)),
	_mapLoader(mapLoader)
{
	loadMapData();
}

MapArea::~MapArea()
{
}

void MapArea::loadMapData()
{
	_mapLoader->parse(_mapLoadData);

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
	}

	//add player

	for (auto& data : _mapData)
	{
		if (data.first->_position.x == 0 && data.first->_position.y == 0)
		{
			_player = GameObjectFactory::getInstance()->create(GameObjectType::Player);
	//		_graphicEngineInterface->loadTexture(_player.get());
			data.second.push_back(_player);
			break;
		}
	}

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
		--tileOffsetX;
		break;
	case Directions::West:
		++tileOffsetX;
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
	return true;
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
