#pragma once

#include "Global.h"
#include "GameObject.h"

class GameLogicObjectInterface
{
public:
	GameLogicObjectInterface() {};
	~GameLogicObjectInterface() {};

	virtual void inspect(std::shared_ptr<GameObject> gameObject) = 0;
	virtual void attack(std::shared_ptr<GameObject> gameObject, const std::shared_ptr<EquipSlot> equipSlot) = 0;
	virtual void open(std::shared_ptr<GameObject> gameObject) = 0;
	virtual void moveObject(std::shared_ptr<GameObject> gameObject, Directions direction) = 0;
	virtual void dead(std::shared_ptr<GameObject> gameObject) = 0;
	virtual void enterDoor(std::shared_ptr<GameObject> gameObject) = 0;
};

