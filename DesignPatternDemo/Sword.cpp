#include "Sword.h"
#include "EquipSlot.h"

Sword::Sword() : ObjectModifier(ObjectModifierType::weapon)
{
	int minDamage = Utilities::getRandomNumber(20, 30);
	int maxDamage = Utilities::getRandomNumber(50, 65);
	int staminaUsage = Utilities::getRandomNumber(12, 18);

	init(minDamage, maxDamage, 1, staminaUsage, 0, 0, 0);
}

Sword::~Sword()
{
}