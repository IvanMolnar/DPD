#pragma once

#include "Global.h"
#include "GameObject.h"

class GameLogicObjectInterface
{
public:
	GameLogicObjectInterface() {};
	~GameLogicObjectInterface() {};

	virtual void moveObject(GameObject* gameObject, Directions direction) = 0;
	virtual void dead(GameObject* gameObject) = 0;
	virtual void enterDoor(GameObject* gameObject) = 0;
};

