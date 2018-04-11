#pragma once

#include "GameObject.h"

#include "ConsoleLogger.h"


#include <map>

//test
#include "GameObjectFactory.h"
#include "TileFactory.h"


class MapArea
{
public:
	MapArea(std::unique_ptr<std::string> mapLoadData);
	~MapArea();


	std::shared_ptr<GameObject> getPlayer();
	bool canMove(GameObject* const gameObject, Directions direction);
	void move(GameObject* const gameObject, Directions direction);
//	void drawMap();
	GameObject* getObjectNextTo(GameObject* const gameObject, Directions direction);
	std::list<GameObject*> getGameObjectByType(GameObjectType gameObjectType);
	std::list<GameObject*> getGameObjects();
	void remove(std::shared_ptr<GameObject> gameObject);

	unsigned int getMapId();
	std::vector<MyObjectDisplayData*> getDisplayData();

private:

	std::shared_ptr<GameObject> _player;



	unsigned int _mapId;


	std::unique_ptr<std::string> _mapLoadData;

	std::map<std::shared_ptr<Tile>, std::list<std::shared_ptr<GameObject>>> _mapData;

	void loadMapData();


	//
	std::shared_ptr<Tile> getTileFromDirection(GameObject* const gameObject, Directions direction);
	std::shared_ptr<Tile> getTileFromObject(GameObject* const gameObject);
	std::shared_ptr<Tile> getTileFromPosition(position2d position);
};

