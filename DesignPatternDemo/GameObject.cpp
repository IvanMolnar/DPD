#include "GameObject.h"
#include "StateUp.h"
#include "StateCrouching.h"
#include "StateDead.h"

#include <sstream>

GameObject::GameObject(GameObjectType type)
{
	_type = type;
	_FSM = std::make_unique<FSM>(new StateUp(this));
	_inventoryManager = std::make_unique<InventoryManager>();

	_stats = std::make_shared<GameObjectStats>(this);
}

GameObject::~GameObject()
{

}

void GameObject::sendEvent(Events event, Directions direction, const std::string& data, std::shared_ptr<GameObject> object)
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

std::shared_ptr<GameObjectStats> GameObject::getStats()
{
	return _stats;
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

void GameObject::preMove(Directions direction)
{
}

void GameObject::move(Directions direction)
{
	preMove(direction);
	_gameLogicObjectInterface->moveObject(shared_from_this(), direction);
	postMove(direction);
}

void GameObject::postMove(Directions direction)
{
}

void GameObject::attack(std::shared_ptr<GameObject> gameObject, const std::shared_ptr<EquipSlot> equipSlot)
{
	_gameLogicObjectInterface->attack(gameObject, equipSlot);
}

void GameObject::open(std::shared_ptr<GameObject> gameObject)
{
	_gameLogicObjectInterface->open(gameObject);
}

void GameObject::inspect(std::shared_ptr<GameObject> gameObject)
{
	_gameLogicObjectInterface->inspect(gameObject);
}

void GameObject::dead()
{
	_gameLogicObjectInterface->dead(shared_from_this());
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
