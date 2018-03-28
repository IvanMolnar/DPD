#pragma once

#include "Global.h"
#include <memory>

class EquipSlot;
class GameObject;

class ObjectCommandInterface
{
public:
	ObjectCommandInterface() {};
	~ObjectCommandInterface() {};

	virtual void move(Directions direction) = 0;
	virtual void inspect(GameObject* const gameObject) = 0;
	virtual void attack(GameObject* const gameObject, EquipSlot* const equipSlot) = 0;
	virtual void open(GameObject* const gameObject) = 0;
	virtual void equip(unsigned int inventorySlot, unsigned int equipSlot) = 0;
	virtual void dead() = 0;
	virtual void changeState(States state) = 0;
};
