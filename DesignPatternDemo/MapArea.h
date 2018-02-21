#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"
#include "ConsoleLogger.h"

class MapArea
{
public:
	MapArea(std::unique_ptr<std::string> mapLoadData);
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

	unsigned int getMapId();
	void getLevelDisplayData();

private:

	GameObject* _player;



	unsigned int _mapId;
	std::string generateScreenData();


	std::unique_ptr<std::string> _mapLoadData;

	void loadMapData();
};

