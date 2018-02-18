#include "Player.h"

Player::Player(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectTypes::typePlayer)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Player::~Player()
{
}

void Player::move(Directions direction)
{
	_gameLogicObjectInterface->moveObject(this, direction);
}

void Player::inspect(GameObject* gameObject)
{
	WRITE_LOG_GAME(gameObject->getInfo());
}

std::string Player::getInfo()
{
	std::string info = GameObject::getInfo();

	info += GameObject::getEquipItemsString();
	info += GameObject::getInventoryItemsString();

	return info;
}

void Player::open(GameObject* gameObject)
{
	if (gameObject->getType() == GameObjectTypes::typeContainer)
	{
		std::list<ObjectModifier*> items = gameObject->getInventoryItems();

		for each (ObjectModifier* item in items)
		{
			addItemToInventory(item);
			gameObject->removeItemFromInventory(item);
		}

		gameObject->changeState(States::dead);
	}
	else if (gameObject->getType() == GameObjectTypes::typeDoor)
	{
		_gameLogicObjectInterface->enterDoor(gameObject);
	}
}

void Player::dead()
{
	_gameLogicObjectInterface->dead(this);
}