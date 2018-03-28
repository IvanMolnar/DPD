#pragma once

#include "ObjectModifier.h"
#include <memory>

class EquipSlot
{
public:
	EquipSlot(int type);
	~EquipSlot();

	// returns nullptr if can't equip
	std::shared_ptr<ObjectModifier> equip(std::shared_ptr<ObjectModifier> modifier);

	std::shared_ptr<ObjectModifier> unequip();
	const std::shared_ptr<ObjectModifier> getObjectModifier();

	// returns list of types that can hold
	std::list<ObjectModifierType> getType();

	std::string getTypeString();
	bool doesSupportType(ObjectModifierType type);

	std::string getInfo();

private:
	std::shared_ptr<ObjectModifier> _modifier;

	// type of ObjectModifiers that can hold
	// example: sword and magic
	int _type;
};

