#pragma once

#include "ObjectModifier.h"

class EquipSlot
{
public:
	EquipSlot(int type, string ownerName);
	~EquipSlot();

	bool equip(ObjectModifier* modifier, ObjectModifier* unequiped);

	ObjectModifier* unequip();
	ObjectModifier* getObjectModifier();

	// returns list of types that can hold
	list<ObjectModifierType> getType();

	string getTypeString();
	bool doesSupportType(ObjectModifierType type);

	string getInfo();

private:
	ObjectModifier* _modifier;
	string _ownerName;

	// type of ObjectModifiers that can hold
	// example: sword and magic
	int _type;
};

