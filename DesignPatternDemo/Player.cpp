#include "Player.h"

Player::Player(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectType::Player)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Player::~Player()
{
}

std::string Player::getInfo()
{
	std::string info = GameObject::getInfo();

	info += GameObject::getEquipItemsString();
	info += GameObject::getInventoryItemsString();

	return info;
}
