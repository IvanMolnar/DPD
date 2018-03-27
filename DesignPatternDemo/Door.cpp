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

void Door::inspect(std::shared_ptr<GameObject> gameObject)
{
	return;
}

void Door::open(std::shared_ptr<GameObject> gameObject)
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
