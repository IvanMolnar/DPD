#include "Enemy.h"
#include "Items\EquipSlot.h"

Enemy::Enemy(void* gameLogicObjectInterface) : GameObject(static_cast<GameLogicObjectInterface*>(gameLogicObjectInterface), GameObjectType::Enemy)
{
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