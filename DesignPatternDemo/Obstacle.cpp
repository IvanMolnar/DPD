#include "Obstacle.h"


Obstacle::Obstacle() : GameObject(GameObjectTypes::typeObstacle)
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::sendEvent(Events event, Directions direction, string& data, GameObject* object)
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

string Obstacle::getInfo()
{
	return "A wall";
}
