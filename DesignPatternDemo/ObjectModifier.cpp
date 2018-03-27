#include "ObjectModifier.h"

#include <sstream>

ObjectModifier::ObjectModifier(ObjectModifierType objectModifierType)
{
	_type = objectModifierType;
}

ObjectModifier::~ObjectModifier()
{
}

int ObjectModifier::getDamage()
{
	return Utilities::getRandomNumber(_stats.damageMin, _stats.damageMax);
}

int ObjectModifier::getProtection()
{
	return Utilities::getRandomNumber(_stats.protectionMin, _stats.protectionMax);
}

void ObjectModifier::init(int damageMin, int damageMax, int range, int staminaUsage, int manaUsage, int protectionMin, int protectionMax)
{
	_stats.damageMin = damageMin;
	_stats.damageMax = damageMax;
	_stats.range = range;
	_stats.staminaUsage = staminaUsage;
	_stats.manaUsage = manaUsage;
	_stats.protectionMin = protectionMin;
	_stats.protectionMax = protectionMax;
}

ObjectModifier::stats ObjectModifier::getStats()
{
	return _stats;
}

ObjectModifierType ObjectModifier::getType()
{
	return _type;
}

std::string ObjectModifier::getTypeString()
{
	std::stringstream ss;

	switch (_type)
	{
	case weapon:
		ss << "Weapon ";
		break;
	case spell:
		ss << "Magic ";
		break;
	case armor:
		ss << "Armor ";
		break;
	default:
	//	WRITE_LOG_WARNING("EquipSlot name does not exists!");
		return "EquipSlot name does not exists!";
	}

	if (_type != armor)
	{
		ss << "damage: " << _stats.damageMin << " - " << _stats.damageMax << " stamina usage: " << _stats.staminaUsage << " mana usage: " << _stats.manaUsage << " range: " << _stats.range << std::endl;
	}
	else
	{
		ss << "protection: " << _stats.protectionMin << " - " << _stats.protectionMax << std::endl;
	}

	return ss.str();
}