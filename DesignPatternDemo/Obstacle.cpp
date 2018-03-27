#include "Obstacle.h"


Obstacle::Obstacle(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectType::Obstacle)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Obstacle::~Obstacle()
{
}

void Obstacle::sendEvent(Events event, Directions direction, const std::string& data, std::shared_ptr<GameObject> object)
{
	// obstacle don't have events
	return;
}

void Obstacle::move(Directions direction)
{
	return;
}

void Obstacle::inspect(std::shared_ptr<GameObject> gameObject)
{
	return;
}

void Obstacle::attack(std::shared_ptr<GameObject> target)
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
