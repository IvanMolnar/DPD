#pragma once

#include "Utility\Utility.h"

#include <list>

enum ObjectModifierType
{
	weapon = 1,
	armor = 2,
	spell = 4
};

class ObjectModifier
{
public:
	ObjectModifier(ObjectModifierType objectModifierType);
	virtual ~ObjectModifier();

	struct stats
	{
		int damageMin;
		int damageMax;
		int range;
		int staminaUsage;
		int manaUsage;
		int protectionMin;
		int protectionMax;
	};

	stats getStats();
	ObjectModifierType getType();
	std::string getTypeString();
	int getProtection();
	void init(int damageMin, int damageMax, int range, int staminaUsage, int manaUsage, int protectionMin, int protectionMax);

protected:
	stats _stats;
	ObjectModifierType _type;

	int getDamage();
	
};

