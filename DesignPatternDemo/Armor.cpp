#include "Armor.h"

Armor::Armor() : ObjectModifier(ObjectModifierType::armor)
{
	int minProtection = Utilities::getRandomNumber(1, 4);
	int maxProtection = Utilities::getRandomNumber(5, 10);

	init(0, 0, 0, 0, 0, minProtection, maxProtection);
}

Armor::~Armor()
{
}

bool Armor::apply(ObjectModifierInterface * objectModifierInterface, std::array<float, 3> modifiers)
{
	return false;
}

bool Armor::applySelf(ObjectModifierInterface * objectModifierInterface, std::array<float, 3> modifiers)
{
	return false;
}
