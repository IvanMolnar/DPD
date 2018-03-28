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
	virtual void inspect(const GameObject * const gameObject) = 0;
	virtual void attack(const GameObject * const gameObject, const EquipSlot * const equipSlot) = 0;
	virtual void open(const GameObject * const gameObject) = 0;
	virtual void equip(unsigned int inventorySlot, unsigned int equipSlot) = 0;
	virtual void dead() = 0;
	virtual void changeState(States state) = 0;
};
