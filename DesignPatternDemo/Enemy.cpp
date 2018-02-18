#include "Enemy.h"
#include "GameLogicObjectInterface.h"
#include "EquipSlot.h"

Enemy::Enemy(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectTypes::typeEnemy)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Enemy::~Enemy()
{
}

void Enemy::move(Directions direction)
{
	_gameLogicObjectInterface->moveObject(this, direction);
}

void Enemy::inspect(GameObject* gameObject)
{
	return;
}

std::string Enemy::getInfo()
{
	return "Enemy info\n" + GameObject::getInfo();
}

void Enemy::dead()
{
	_gameLogicObjectInterface->dead(this);
}