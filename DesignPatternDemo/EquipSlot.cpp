#include "EquipSlot.h"

#include <sstream>

EquipSlot::EquipSlot(int type) : _type(type)
{
	_modifier = nullptr;
}

EquipSlot::~EquipSlot()
{
}

std::shared_ptr<ObjectModifier> EquipSlot::equip(std::shared_ptr<ObjectModifier> modifier)
{
	std::shared_ptr<ObjectModifier> result;

	if (!modifier)
	{
		return nullptr;
	}

	// check if we can equip this
	if ((_type & modifier->getType()) == 0)
	{
		return nullptr;
	}

	result = _modifier;

	_modifier = modifier;

	return result;
}

std::shared_ptr<ObjectModifier> EquipSlot::unequip()
{
	std::shared_ptr<ObjectModifier> result = _modifier;

	_modifier = nullptr;

	return result;
}

const std::shared_ptr<ObjectModifier> EquipSlot::getObjectModifier()
{
	return _modifier;
}

std::list<ObjectModifierType> EquipSlot::getType()
{
	std::list<ObjectModifierType> result;

	if (_type & ObjectModifierType::weapon)
	{
		result.push_back(ObjectModifierType::weapon);
	}

	if (_type & ObjectModifierType::spell)
	{
		result.push_back(ObjectModifierType::spell);
	}

	if (_type & ObjectModifierType::armor)
	{
		result.push_back(ObjectModifierType::armor);
	}

	return result;
}

std::string EquipSlot::getTypeString()
{
	std::string result;

	std::list<ObjectModifierType> supportedTypes = getType();

	for each (ObjectModifierType supportedType in supportedTypes)
	{
		switch (supportedType)
		{
		case weapon:
			result += "Weapon ";
			break;
		case spell:
			result += "Magic ";
			break;
		case armor:
			result += "Armor ";
			break;
		default:
//			WRITE_LOG_WARNING("EquipSlot name does not exists!");
			result += "EquipSlot name does not exists! ";
			break;
		}
	}

	return result;
}

bool EquipSlot::doesSupportType(ObjectModifierType type)
{
	std::list<ObjectModifierType> types = getType();

	for each (ObjectModifierType ObjectType in types)
	{
		if (ObjectType == type)
		{
			return true;
		}
	}

	return false;
}

std::string EquipSlot::getInfo()
{
	std::stringstream ss;

	ss << std::endl << "Can equip " << getTypeString() << std::endl << "Equiped: ";

	if (_modifier)
	{
		ss << _modifier->getTypeString();
	}
	else
	{
		ss << "None";
	}

	return ss.str();
}
