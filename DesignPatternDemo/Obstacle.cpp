#include "Obstacle.h"


Obstacle::Obstacle(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectTypes::typeObstacle)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Obstacle::~Obstacle()
{
}

void Obstacle::sendEvent(Events event, Directions direction, std::string& data, GameObject* object)
{
	// obstacle don't have events
	return;
}

void Obstacle::move(Directions direction)
{
	return;
}

void Obstacle::inspect(GameObject* gameObject)
{
	return;
}

void Obstacle::attack(GameObject* target)
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
