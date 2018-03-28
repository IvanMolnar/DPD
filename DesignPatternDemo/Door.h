#pragma once

#include "GameObject.h"

class Door : public GameObject
{
public:
	Door(GameLogicObjectInterface* gameLogicObjectInterface);
	~Door();

	void move(Directions direction);
	void inspect(const GameObject * const gameObject);
	void open(const GameObject * const gameObject);
	void dead();

	std::string getMapName();

	std::string getInfo();
};
