#include "InventoryManager.h"



InventoryManager::InventoryManager()
{
}


InventoryManager::~InventoryManager()
{
}

void InventoryManager::addEquipSlot(int slotType)
{
	_slots.push_back(std::make_shared<EquipSlot>(slotType));
}
