#include "Enemy.h"
#include "EquipSlot.h"

Enemy::Enemy(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectType::Enemy)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Enemy::~Enemy()
{
}

void Enemy::inspect(GameObject* const gameObject)
{
	return;
}

std::string Enemy::getInfo()
{
	return "Enemy info\n" + GameObject::getInfo();
}