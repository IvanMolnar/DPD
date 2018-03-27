#include "Container.h"

Container::Container(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectType::Container)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Container::~Container()
{
}

void Container::move(Directions direction)
{
	return;
}

void Container::inspect(std::shared_ptr<GameObject> gameObject)
{
	return;
}

std::string Container::getInfo()
{
	return "Looks like ordinary chest";
}