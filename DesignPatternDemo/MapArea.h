#pragma once

#include "GameObject.h"

#include "ConsoleLogger.h"

class MapArea
{
public:
	MapArea(std::unique_ptr<std::string> mapLoadData);
	~MapArea();

	

	void loadLevel(std::string fileName);



	std::shared_ptr<GameObject> getPlayer();
	bool canMove(std::shared_ptr<GameObject> gameObject, Directions direction);
	void move(std::shared_ptr<GameObject> gameObject, Directions direction);
//	void drawMap();
	GameObject* getObjectNextTo(std::shared_ptr<GameObject> gameObject, Directions direction);
	std::list<GameObject*> getGameObjectByType(GameObjectType gameObjectType);
	std::list<GameObject*> getGameObjects();
	void remove(std::shared_ptr<GameObject> gameObject);

	unsigned int getMapId();
	void getLevelDisplayData();

private:

	std::shared_ptr<GameObject> _player;



	unsigned int _mapId;
	std::string generateScreenData();


	std::unique_ptr<std::string> _mapLoadData;

	void loadMapData();
};

