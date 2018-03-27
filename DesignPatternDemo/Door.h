#pragma once

#include "GameObject.h"

class Door : public GameObject
{
public:
	Door(GameLogicObjectInterface* gameLogicObjectInterface);
	~Door();

	void move(Directions direction);
	void inspect(std::shared_ptr<GameObject> gameObject);
	void open(std::shared_ptr<GameObject> gameObject);
	void dead();

	std::string getMapName();

	std::string getInfo();
};
