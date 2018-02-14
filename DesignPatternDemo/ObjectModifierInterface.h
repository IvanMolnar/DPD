#pragma once

#include "GameObjectStats.h"
#include "Global.h"

#include <list>
#include <array>

class EquipSlot;

class ObjectModifierInterface
{
public:
	ObjectModifierInterface() {};
	~ObjectModifierInterface() {};

	virtual GameObjectStats* getStats() = 0;
	virtual std::list<EquipSlot*> getEquipSlots() = 0;
};
