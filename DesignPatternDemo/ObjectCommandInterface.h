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
	virtual void inspect(std::shared_ptr<GameObject> gameObject) = 0;
	virtual void attack(std::shared_ptr<GameObject> gameObject, const std::shared_ptr<EquipSlot> equipSlot) = 0;
	virtual void open(std::shared_ptr<GameObject> gameObject) = 0;
	virtual void equip(unsigned int inventorySlot, unsigned int equipSlot) = 0;
	virtual void dead() = 0;
	virtual void changeState(States state) = 0;
};
