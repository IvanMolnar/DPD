#pragma once

#include "GameObject.h"

class Door : public GameObject
{
public:
	Door(void* gameLogicObjectInterface);
	~Door();

	void move(Directions direction);
	void inspect(GameObject* const gameObject);
	void open(GameObject* const gameObject);
	void dead();

	std::string getMapName();

	std::string getInfo();
};
