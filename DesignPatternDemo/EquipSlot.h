#pragma once

#include "ObjectModifier.h"

class EquipSlot
{
public:
	EquipSlot(int type, std::string ownerName);
	~EquipSlot();

	bool equip(ObjectModifier* modifier, ObjectModifier* unequiped);

	ObjectModifier* unequip();
	ObjectModifier* getObjectModifier();

	// returns list of types that can hold
	std::list<ObjectModifierType> getType();

	std::string getTypeString();
	bool doesSupportType(ObjectModifierType type);

	std::string getInfo();

private:
	ObjectModifier* _modifier;
	std::string _ownerName;

	// type of ObjectModifiers that can hold
	// example: sword and magic
	int _type;
};

