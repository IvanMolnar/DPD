#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"
#include "ConsoleLogger.h"


#define MaxLevelColumns 16
#define MaxLevelRows 16


class MapArea
{
public:
	MapArea();
	~MapArea();

	void loadLevel(std::string fileName);
	GameObject* getPlayer();
	bool canMove(GameObject* gameObject, Directions direction);
	void move(GameObject* gameObject, Directions direction);
//	void drawMap();
	GameObject* getObjectNextTo(GameObject* gameObject, Directions direction);
	std::list<GameObject*> getGameObjectByType(GameObjectTypes gameObjectType);
	std::list<GameObject*> getGameObjects();
	void remove(GameObject* gameObject);

	void getLevelDisplayData();

private:
	GameObject* _mapData[MaxLevelColumns][MaxLevelRows];
	GameObject* _player;

	std::string generateScreenData();
};

