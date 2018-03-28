#pragma once

#include "Global.h"
#include "GameObject.h"

class GameLogicObjectInterface
{
public:
	GameLogicObjectInterface() {};
	~GameLogicObjectInterface() {};

	virtual void inspect(const GameObject * const gameObject) = 0;
	virtual void attack(const GameObject * const gameObject, const EquipSlot * const equipSlot) = 0;
	virtual void open(const GameObject * const gameObject) = 0;
	virtual void moveObject(const GameObject * const gameObject, Directions direction) = 0;
	virtual void dead(const GameObject * const gameObject) = 0;
	virtual void enterDoor(const GameObject * const gameObject) = 0;
};

