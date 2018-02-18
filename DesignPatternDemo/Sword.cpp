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

bool Sword::apply(ObjectModifierInterface* objectModifierInterface, std::array<float, 3> modifiers)
{
	std::list<EquipSlot*> enemySlots = objectModifierInterface->getEquipSlots();

	int enemyArmorProtection = 0;

	for each (EquipSlot* slot in enemySlots)
	{
		ObjectModifier* item = slot->getObjectModifier();

		if (item && item->getType() == ObjectModifierType::armor)
		{
			enemyArmorProtection += slot->getObjectModifier()->getProtection();
		}
	}

	int damageTotal = ((float)getDamage() * modifiers[0]) - enemyArmorProtection;

	if (damageTotal > 0)
	{
		GameObjectStats* stats = objectModifierInterface->getStats();

		bool dead = stats->addHealth(-damageTotal);

		std::stringstream ss;

		ss << damageTotal << " damage";

		if (dead)
		{
			ss << " and kills";
		}

		ss << std::endl;

		WRITE_LOG_GAME(ss.str());

		return dead;
	}

	return false;
}

bool Sword::applySelf(ObjectModifierInterface* objectModifierInterface, std::array<float, 3> modifiers)
{
	if (ObjectModifier::applySelf(objectModifierInterface, modifiers))
	{
		GameObjectStats* myStats = objectModifierInterface->getStats();
		ObjectModifier::stats itemStats = getStats();

		myStats->addStamina((float)-itemStats.staminaUsage * modifiers[1]);
		myStats->addMana((float)-itemStats.manaUsage * modifiers[2]);

		return true;
	}

	return false;
}