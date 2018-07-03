#pragma once

#include "GameObjects\GameObject.h"
#include <map>
#include "Factories\GameObjectFactory.h"
#include "MapLoader.h"


class MapArea
{
public:
	MapArea(std::unique_ptr<std::string> mapLoadData, MapLoader* mapLoader);
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
	void loadMapData();

private:

	std::shared_ptr<GameObject> _player;



	unsigned int _mapId;


	std::unique_ptr<std::string> _mapLoadData;

	std::map<std::shared_ptr<GameObject>, std::list<std::shared_ptr<GameObject>>> _mapData;

	


	//
	std::shared_ptr<GameObject> getTileFromDirection(GameObject* const gameObject, Directions direction);
	std::shared_ptr<GameObject> getTileFromObject(GameObject* const gameObject);
	std::shared_ptr<GameObject> getTileFromPosition(position2d position);


	MapLoader* _mapLoader;

	const std::string __namespace__ = "Map";
};

