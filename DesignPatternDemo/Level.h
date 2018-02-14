#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"
#include "ConsoleLogger.h"

#define MaxLevelColumns 16
#define MaxLevelRows 16

class Level
{
public:
	Level(GameLogicObjectInterface* gameLogicObjectInterface);
	~Level();

	void loadLevel(string fileName);
	GameObject* getPlayer();
	bool canMove(GameObject* gameObject, Directions direction);
	void move(GameObject* gameObject, Directions direction);
	void drawMap();
	GameObject* getObjectNextTo(GameObject* gameObject, Directions direction);
	list<GameObject*> getGameObjectByType(GameObjectTypes gameObjectType);
	list<GameObject*> getGameObjects();
	void remove(GameObject* gameObject);

private:
	GameObject* _mapData[MaxLevelColumns][MaxLevelRows];
	GameObject* _player;
	GameLogicObjectInterface* _gameLogicObjectInterface;
	CConsoleLoggerEx* _display;

	string generateScreenData();
	
};

