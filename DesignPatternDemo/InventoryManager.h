#pragma once

#include "EquipSlot.h"
#include <vector>

class InventoryManager
{
public:
	InventoryManager();
	~InventoryManager();

	void addEquipSlot(int slotType);

private:
	std::vector<std::shared_ptr<EquipSlot>> _slots;
};

