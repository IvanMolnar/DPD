#include "Obstacle.h"

Obstacle::Obstacle(void* gameLogicObjectInterface) : GameObject(static_cast<GameLogicObjectInterface*>(gameLogicObjectInterface), GameObjectType::Obstacle)
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::sendEvent(Events event, Directions direction, const std::string& data, GameObject* const object)
{
	// obstacle don't have events
	return;
}

void Obstacle::move(Directions direction)
{
	return;
}

void Obstacle::inspect(GameObject* const gameObject)
{
	return;
}

void Obstacle::attack(GameObject* const target, EquipSlot* const equipSlot)
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
