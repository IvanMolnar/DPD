#include "MapArea.h"
#include <iostream>
#include <fstream>

#include "GameObjectFactory.h"

MapArea::MapArea()
{
	_player = nullptr;
	//GameObjectFactory::init(gameLogicObjectInterface);

	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			_mapData[x][y] = nullptr;
		}
	}
}

MapArea::~MapArea()
{
	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			if (_mapData[x][y])
			{
				delete _mapData[x][y];
			}
		}
	}
}

void MapArea::loadLevel(std::string fileName)
{
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
				if (_mapData[x][y]->getType() != GameObjectTypes::typePlayer)
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

		for each (char c in line)
		{
			GameObject* gameObject = GameObjectFactory::createGameObject(c);

			if (gameObject && gameObject->getType() == GameObjectTypes::typePlayer)
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
			if (gameObject && gameObject->getType() == GameObjectTypes::typeContainer)
			{
				gameObject->addItemToInventory(new Sword());
				gameObject->addItemToInventory(new Armor());
			}

			if (gameObject && gameObject->getType() == GameObjectTypes::typeEnemy)
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

	infile.close();
}

GameObject* MapArea::getPlayer()
{
	return _player;
}

bool MapArea::canMove(GameObject* gameObject, Directions direction)
{
	int column = -1;
	int row = -1;

	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			if (_mapData[x][y] == gameObject)
			{
				column = x;
				row = y;
				x = MaxLevelColumns;
				break;
			}
		}
	}

	switch (direction)
	{
	case North:
		--column;
		break;
	case South:
		++column;
		break;
	case West:
		--row;
		break;
	case East:
		++row;
		break;
	default:
		break;
	}

	if ((column > 0 && column < MaxLevelColumns) && (row > 0 && row < MaxLevelRows))
	{
		if (!_mapData[column][row])
		{
			return true;
		}
	}

	return false;
}

void MapArea::move(GameObject* gameObject, Directions direction)
{
	int previousColumn = -1;
	int previousRow = -1;
	int column = -1;
	int row = -1;

	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			if (_mapData[x][y] == gameObject)
			{
				column = x;
				previousColumn = x;
				row = y;
				previousRow = y;
			}
		}
	}

	switch (direction)
	{
	case North:
		--column;
		break;
	case South:
		++column;
		break;
	case West:
		--row;
		break;
	case East:
		++row;
		break;
	default:
		break;
	}

	if ((column > 0 && column < MaxLevelColumns) && (row > 0 && row < MaxLevelRows))
	{
		_mapData[column][row] = _mapData[previousColumn][previousRow];
		_mapData[previousColumn][previousRow] = nullptr;
	}

}

std::string MapArea::generateScreenData()
{
	std::string result;

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
	}

	return result;
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

GameObject* MapArea::getObjectNextTo(GameObject* gameObject, Directions direction)
{
	GameObject* result = nullptr;

	if (direction == Directions::None)
	{
		return result;
	}

	int column = -1;
	int row = -1;

	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			if (_mapData[x][y] == gameObject)
			{
				column = x;
				row = y;
				x = MaxLevelColumns;
				break;
			}
		}
	}

	if ((column > 0 && column < MaxLevelColumns) && (row > 0 && row < MaxLevelRows))
	{
		switch (direction)
		{
		case North:
			--column;
			break;
		case South:
			++column;
			break;
		case West:
			--row;
			break;
		case East:
			++row;
			break;
		default:
			break;
		}

		result = _mapData[column][row];
	}

	return result;
}

std::list<GameObject*> MapArea::getGameObjectByType(GameObjectTypes gameObjectType)
{
	std::list<GameObject*> result;

	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			GameObject* gameObject = _mapData[x][y];

			if (gameObject && gameObject->getType() == gameObjectType)
			{
				result.push_back(gameObject);
			}
		}
	}

	return result;
}

std::list<GameObject*> MapArea::getGameObjects()
{
	std::list<GameObject*> result;

	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			GameObject* gameObject = _mapData[x][y];

			if (gameObject)
			{
				result.push_back(gameObject);
			}
		}
	}

	return result;
}

void MapArea::remove(GameObject* gameObject)
{
	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			if (_mapData[x][y] == gameObject)
			{
				if (gameObject == _player)
				{
					_player = nullptr;
				}

				delete gameObject;
				gameObject = nullptr;
				_mapData[x][y] = nullptr;
				return;
			}
		}
	}
}
