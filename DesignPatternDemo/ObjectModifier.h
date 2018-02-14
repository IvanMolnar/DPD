#pragma once

#include "ObjectModifierVisitor.h"
#include "Utility.h"

#include <list>

using namespace std;

enum ObjectModifierType
{
	weapon = 1,
	armor = 2,
	spell = 4
};

class ObjectModifier : public ObjectModifierVisitor
{
public:
	ObjectModifier(ObjectModifierType objectModifierType);
	virtual ~ObjectModifier();

	// returns if enemy is alive
	virtual bool apply(ObjectModifierInterface* objectModifierInterface, array<float, 3> modifiers) = 0;

	virtual bool applySelf(ObjectModifierInterface* objectModifierInterface, array<float, 3> modifiers);

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
	string getTypeString();
	int getProtection();
	void init(int damageMin, int damageMax, int range, int staminaUsage, int manaUsage, int protectionMin, int protectionMax);

protected:
	stats _stats;
	ObjectModifierType _type;

	int getDamage();
	
};

