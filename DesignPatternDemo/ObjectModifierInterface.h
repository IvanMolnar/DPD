#pragma once

#include "GameObjectStats.h"
#include "Global.h"

#include <list>
#include <array>
#include <memory>

class EquipSlot;

class ObjectModifierInterface
{
public:
	ObjectModifierInterface() {};
	~ObjectModifierInterface() {};

	virtual std::shared_ptr<GameObjectStats> getStats() = 0;
};
