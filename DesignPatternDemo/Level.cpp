#include "Level.h"
#include <iostream>
#include <fstream>

#include "GameObjectFactory.h"

using namespace std;

Level::Level(GameLogicObjectInterface* gameLogicObjectInterface): _gameLogicObjectInterface(gameLogicObjectInterface)
{
	_player = nullptr;
	_display = new CConsoleLoggerEx();
	_display->Create("Display");
	GameObjectFactory::init(gameLogicObjectInterface);

	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			_mapData[x][y] = nullptr;
		}
	}
}

Level::~Level()
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

	_display->Close();
	delete _display;
}

void Level::loadLevel(string fileName)
{
	string line;
	ifstream infile;

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
				string s("01");
				gameObject->sendEvent(Events::equip, Directions::None, s);

				if (i == 1)
				{
					gameObject->addItemToInventory(new Sword());
					string s("02");
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

	drawMap();
}

GameObject* Level::getPlayer()
{
	return _player;
}

bool Level::canMove(GameObject* gameObject, Directions direction)
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

void Level::move(GameObject* gameObject, Directions direction)
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

string Level::generateScreenData()
{
	string result;

	for (int x = 0; x < MaxLevelColumns; x++)
	{
		for (int y = 0; y < MaxLevelRows; y++)
		{
			string c(" ");

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

void Level::drawMap()
{
	stringstream ss;
	ss << generateScreenData();
	
	if (_player)
	{
		ss << "State: " << _player->getStateString() << endl;
		ss << _player->getInfo();
	}

	_display->cls();
	_display->cprintf(ss.str().c_str());
}

GameObject* Level::getObjectNextTo(GameObject* gameObject, Directions direction)
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

list<GameObject*> Level::getGameObjectByType(GameObjectTypes gameObjectType)
{
	list<GameObject*> result;

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

list<GameObject*> Level::getGameObjects()
{
	list<GameObject*> result;

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

void Level::remove(GameObject* gameObject)
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
