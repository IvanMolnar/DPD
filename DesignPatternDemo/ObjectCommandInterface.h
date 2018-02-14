#pragma once

#include "Global.h"

class GameObject;

class ObjectCommandInterface
{
public:
	ObjectCommandInterface() {};
	~ObjectCommandInterface() {};

	virtual void move(Directions direction) = 0;
	virtual void inspect(GameObject* gameObject) = 0;
	virtual void attack(GameObject* gameObject) = 0;
	virtual void open(GameObject* gameObject) = 0;
	virtual void equip(unsigned int inventorySlot, unsigned int equipSlot) = 0;
	virtual void dead() = 0;
	virtual void changeState(States state) = 0;
};
