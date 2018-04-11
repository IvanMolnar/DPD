#include "MapArea.h"
#include <iostream>
#include <fstream>



MapArea::MapArea(std::unique_ptr<std::string> mapLoadData) :
	_mapId(0),
	_mapLoadData(std::move(mapLoadData))
{
	loadMapData();
}

MapArea::~MapArea()
{
}

void MapArea::loadMapData()
{
	//test
	int row = 0;
	int column = 0;
	for (int i = 0; i < 20; i++, column++)
	{
		std::shared_ptr<Tile> newTile = TileFactory::getInstance()->create(TileType::Grass);
		newTile->_position.x = column;
		newTile->_position.y = row;

		_mapData[newTile] = std::list<std::shared_ptr<GameObject>>();

		if (column == 4)
		{
			column = 0;
			++row;
		}
	}

	//add player
	 _mapData[0].push_back(GameObjectFactory::getInstance()->create(GameObjectType::Player));
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

}

std::string MapArea::generateScreenData()
{
	std::string result;
	/*
	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			std::string c(" ");

			if (_mapData[x][y])
			{
				c = GameObjectFactory::getCharIdFromType(_mapData[x][y]->getType());
			}

			result += c;
		}

		result += '\n';
	}*/

	return result;
}
unsigned int MapArea::getMapId()
{
	return _mapId;
}
void MapArea::getLevelDisplayData()
{
}
/*
void MapArea::drawMap()
{
	std::stringstream ss;
	ss << generateScreenData();
	
	if (_player)
	{
		ss << "State: " << _player->getStateString() << endl;
		ss << _player->getInfo();
	}

	_display->cls();
	_display->cprintf(ss.str().c_str());
}*/

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
