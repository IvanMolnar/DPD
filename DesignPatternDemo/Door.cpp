#include "Door.h"


Door::Door(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectType::Door)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Door::~Door()
{
}

void Door::move(Directions direction)
{
	return;
}

void Door::inspect(const GameObject * const gameObject)
{
	return;
}

void Door::open(const GameObject * const gameObject)
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
