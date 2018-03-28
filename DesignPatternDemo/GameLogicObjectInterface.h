#pragma once

#include "Global.h"
#include "GameObject.h"

class GameLogicObjectInterface
{
public:
	GameLogicObjectInterface() {};
	~GameLogicObjectInterface() {};

	virtual void inspect(GameObject* const gameObject) = 0;
	virtual void attack(GameObject* const gameObject, EquipSlot* const equipSlot) = 0;
	virtual void open(GameObject* const gameObject) = 0;
	virtual void moveObject(GameObject* const gameObject, Directions direction) = 0;
	virtual void dead(GameObject* const gameObject) = 0;
	virtual void enterDoor(GameObject* const gameObject) = 0;
};

