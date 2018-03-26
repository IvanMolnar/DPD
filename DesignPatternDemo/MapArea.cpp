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
//	for ()

}

void MapArea::loadLevel(std::string fileName)
{/*
	std::string line;
	std::ifstream infile;

	int currentRow = 0;
	int currentColumn = 0;

	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			if (_mapData[x][y])
			{
				if (_mapData[x][y]->getType() != GameObjectType::Player)
				{
					delete _mapData[x][y];
				}
				else
				{
					_mapData[x][y] = nullptr;
				}
				
			}
		}
	}

	infile.open(fileName);

	if (!infile.good())
	{
		WRITE_LOG_WARNING("Could not open map file " + fileName)
		return;
	}

	int i = 0;

	while (!infile.eof())
	{
		getline(infile, line);

		currentRow = 0;

		for (char c : line)
		{
			GameObject* gameObject = GameObjectFactory::createGameObject(c);

			if (gameObject && gameObject->getType() == GameObjectType::Player)
			{
				if (_player)
				{
					delete gameObject;
					gameObject = _player;
				}
				else
				{
					_player = gameObject;
				}
				
			}

			//debug
			if (gameObject && gameObject->getType() == GameObjectType::Container)
			{
				gameObject->addItemToInventory(new Sword());
				gameObject->addItemToInventory(new Armor());
			}

			if (gameObject && gameObject->getType() == GameObjectType::Enemy)
			{
				gameObject->addItemToInventory(new Sword());
				std::string s("01");
				gameObject->sendEvent(Events::equip, Directions::None, s);

				if (i == 1)
				{
					gameObject->addItemToInventory(new Sword());
					std::string s("02");
					gameObject->sendEvent(Events::equip, Directions::None, s);
				}

				++i;
			}
			///////////////////////////////////////////////////////////////////////
			
			_mapData[currentColumn][currentRow] = gameObject;

			++currentRow;
		}

		++currentColumn;

	}

	infile.close();*/
}

std::shared_ptr<GameObject> MapArea::getPlayer()
{
	return _player;
}

bool MapArea::canMove(std::shared_ptr<GameObject> gameObject, Directions direction)
{
	return true;
}

void MapArea::move(std::shared_ptr<GameObject> gameObject, Directions direction)
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

GameObject* MapArea::getObjectNextTo(std::shared_ptr<GameObject> gameObject, Directions direction)
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
