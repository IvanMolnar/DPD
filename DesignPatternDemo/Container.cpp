#include "Container.h"

Container::Container(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectTypes::typeContainer)
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

void Container::inspect(GameObject* gameObject)
{
	return;
}

std::string Container::getInfo()
{
	return "Looks like ordinary chest";
}

void Container::dead()
{
	_gameLogicObjectInterface->dead(this);
}