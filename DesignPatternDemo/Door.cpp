#include "Door.h"


Door::Door(void* gameLogicObjectInterface) : GameObject(static_cast<GameLogicObjectInterface*>(gameLogicObjectInterface), GameObjectType::Door)
{
}

Door::~Door()
{
}

void Door::move(Directions direction)
{
	return;
}

void Door::inspect(GameObject* const gameObject)
{
	return;
}

void Door::open(GameObject* const gameObject)
{
	return;
}

void Door::dead()
{
	return;
}

std::string Door::getMapName()
{
	return "testmap2.txt";
}

std::string Door::getInfo()
{
	return "A door, how exciting!";
}
