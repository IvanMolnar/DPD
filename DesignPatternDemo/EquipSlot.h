#pragma once

#include "ObjectModifier.h"
#include <memory>

class EquipSlot
{
public:
	EquipSlot(int type);
	~EquipSlot();

	// returns nullptr if can't equip
	// returns unequiped item if can equip
	std::unique_ptr<ObjectModifier> equip(std::unique_ptr<ObjectModifier> modifier);

	// returns nullptr if slot is empty
	// otherwise returns unequiped item
	std::unique_ptr<ObjectModifier> unequip();

	// returns list of types that can hold
	std::list<ObjectModifierType> getType();

	std::string getTypeString();
	bool doesSupportType(ObjectModifierType type);

	std::string getInfo();

private:
	std::unique_ptr<ObjectModifier> _modifier;

	// type of ObjectModifiers that can hold
	// example: sword and magic
	int _type;
};

