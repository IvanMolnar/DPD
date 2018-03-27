#include "Enemy.h"
#include "EquipSlot.h"

Enemy::Enemy(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectType::Enemy)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Enemy::~Enemy()
{
}

void Enemy::move(Directions direction)
{
	_gameLogicObjectInterface->moveObject(shared_from_this(), direction);
}

void Enemy::inspect(std::shared_ptr<GameObject> gameObject)
{
	return;
}

std::string Enemy::getInfo()
{
	return "Enemy info\n" + GameObject::getInfo();
}

void Enemy::dead()
{
	_gameLogicObjectInterface->dead(shared_from_this());
}