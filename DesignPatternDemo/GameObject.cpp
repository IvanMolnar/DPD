#include "GameObject.h"
#include "StateUp.h"
#include "StateCrouching.h"
#include "StateDead.h"
#include "EquipSlot.h"

#include <sstream>

GameObject::GameObject(GameObjectType type)
{
	_type = type;
	_FSM = new FSM(new StateUp(this));
	_stats = new GameObjectStats(this);
	
	std::string strType = getTypeString();

	if (_type != GameObjectType::Obstacle)
	{
		_equipSlots.push_back(new EquipSlot(ObjectModifierType::armor, strType));
		_equipSlots.push_back(new EquipSlot(ObjectModifierType::weapon | ObjectModifierType::spell, strType));
		_equipSlots.push_back(new EquipSlot(ObjectModifierType::weapon | ObjectModifierType::spell, strType));
	}
}

GameObject::~GameObject()
{
	delete _FSM;
	delete _stats;

	for each (EquipSlot* slot in _equipSlots)
	{
		ObjectModifier* item = slot->getObjectModifier();

		if (item)
		{
			delete item;
		}

		delete slot;
	}

	for each (ObjectModifier* item in _inventoryItems)
	{
		delete item;
	}
}

void GameObject::sendEvent(Events event, Directions direction, const std::string& data, GameObject* object)
{
	_FSM->processCurrentState(event, direction, object, data);
}

void GameObject::changeState(States state)
{
	State* newState = nullptr;

	switch (state)
	{
	case States::standingUp:
		newState = new StateUp(this);
		break;
	case States::sneaking:
		newState = new StateCrouching(this);
		break;
	case States::dead:
		newState = new StateDead(this);
		break;
	default:
		std::stringstream ss;
//		ss << "State " << state << " does not exist";
		WRITE_LOG_WARNING(ss.str());
		break;
	}

	_FSM->changeState(newState);
}

GameObjectType GameObject::getType()
{
	return _type;
}

std::string GameObject::getTypeString()
{
	switch (_type)
	{
	case GameObjectType::Player:
		return "Player";
	case GameObjectType::Obstacle:
		return "Obstacle";
	case GameObjectType::Enemy:
		return "Enemy";
	case GameObjectType::Container:
		return "Container";
	default:
		return "<INVALID TYPE>";
	}
}

States GameObject::getState()
{
	return _FSM->getCurrentState();
}

std::string GameObject::getStateString()
{
	return _FSM->getCurrentStateString();
}

std::string GameObject::getInfo()
{
	return _stats->getInfo();
}

GameObjectStats* GameObject::getStats()
{
	return _stats;
}

void GameObject::acceptModifier(ObjectModifier& objectModifier)
{
	objectModifier.apply(this, this->getModifiersPercent());
}

bool GameObject::acceptModifierSelf(ObjectModifier& objectModifier)
{
	return objectModifier.applySelf(this, this->getModifiersPercent());
}

std::list<EquipSlot*> GameObject::getEquipSlots()
{
	return _equipSlots;
}

std::list<ObjectModifier*> GameObject::getInventoryItems()
{
	return _inventoryItems;
}

std::string GameObject::getEquipItemsString()
{
	std::stringstream result;

	for each (EquipSlot* slot in _equipSlots)
	{
		result << slot->getInfo() << std::endl;
	}

	return result.str();
}

std::string GameObject::getInventoryItemsString()
{
	std::stringstream result;
	int index = 0;

	for each (ObjectModifier* item in _inventoryItems)
	{
		result << index << ": " << item->getTypeString() << std::endl;
		++index;
	}

	return result.str();
}

void GameObject::addItemToInventory(ObjectModifier* item)
{
	_inventoryItems.push_back(item);
}

void GameObject::removeItemFromInventory(ObjectModifier* item)
{
	_inventoryItems.remove(item);
}

std::array<float, 3> GameObject::getModifiersPercent()
{
	//damage, stamina, mana
	std::array<float, 3> result = {1, 1, 1};
	
	if (getState() == States::sneaking)
	{
		result[0] = 1.4f;
		result[1] = 1.6f;
	}

	return result;
}

void GameObject::attack(GameObject* gameObject)
{
	for (std::list<EquipSlot*>::iterator it = _equipSlots.begin(); it != _equipSlots.end(); it++)
	{
		EquipSlot* slot = *it;

		ObjectModifier* item = slot->getObjectModifier();

		// check if it's a weapon
		if (item && (item->getType() == ObjectModifierType::weapon || item->getType() == ObjectModifierType::spell))
		{
			// check if we can attack
			if (item->applySelf(this, this->getModifiersPercent()))
			{
				std::stringstream ss;

				if (this->getType() == GameObjectType::Player)
				{
					ss << "Player attacks for ";
				}
				else if (this->getType() == GameObjectType::Enemy)
				{
					ss << "Enemy attacks for ";
				}

				WRITE_LOG_GAME(ss.str());

				// attack
				if (item->apply(gameObject, this->getModifiersPercent()))
				{
					// if gameObject is dead we abort attack
					return;
				}
			}
		}
	}

	// if player attacks enemy then enemy retaliate
	if (this->getType() == GameObjectType::Player)
	{
		std::string s;
		gameObject->sendEvent(Events::attack, Directions::None, s, this);
	}
}

void GameObject::open(GameObject* gameObject)
{
	return;
}

void GameObject::equip(unsigned int inventorySlot, unsigned int equipSlot)
{
	if ((inventorySlot >= _inventoryItems.size()) || (equipSlot >= _equipSlots.size()))
	{
		return;
	}

	int inventoryIndex = 0;
	ObjectModifier* inventoryItem = nullptr;

	for (std::list<ObjectModifier*>::iterator it = _inventoryItems.begin(); it != _inventoryItems.end(); it++)
	{
		if (inventoryIndex == inventorySlot)
		{
			inventoryItem = *it;
			break;
		}

		++inventoryIndex;
	}

	EquipSlot* slot = nullptr;
	
	int slotIndex = 0;

	for each (EquipSlot* es in _equipSlots)
	{
		if (slotIndex == equipSlot)
		{
			slot = es;
			break;
		}

		++slotIndex;
	}

	ObjectModifier* unequipedItem = nullptr;

	bool equiped = slot->equip(inventoryItem, unequipedItem);

	if (unequipedItem)
	{
		_inventoryItems.push_back(unequipedItem);
	}

	if (equiped)
	{
		_inventoryItems.remove(inventoryItem);
	}
	
}
