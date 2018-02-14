#include "Door.h"


Door::Door() : GameObject(GameObjectTypes::typeDoor)
{
}

Door::~Door()
{
}

void Door::move(Directions direction)
{
	return;
}

void Door::inspect(GameObject* gameObject)
{
	return;
}

void Door::open(GameObject* gameObject)
{
	return;
}

void Door::dead()
{
	return;
}

string Door::getMapName()
{
	return "testmap2.txt";
}

string Door::getInfo()
{
	return "A door, how exciting!";
}
