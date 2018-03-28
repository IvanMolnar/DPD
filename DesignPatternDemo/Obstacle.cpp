#include "Obstacle.h"


Obstacle::Obstacle(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectType::Obstacle)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Obstacle::~Obstacle()
{
}

void Obstacle::sendEvent(Events event, Directions direction, const std::string& data, const GameObject* const object)
{
	// obstacle don't have events
	return;
}

void Obstacle::move(Directions direction)
{
	return;
}

void Obstacle::inspect(const GameObject* const gameObject)
{
	return;
}

void Obstacle::attack(const GameObject* const target, const EquipSlot* const equipSlot)
{
	return;
}

void Obstacle::dead()
{
	return;
}

std::string Obstacle::getInfo()
{
	return "A wall";
}
