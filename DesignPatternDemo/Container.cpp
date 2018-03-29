#include "Container.h"

Container::Container(void* gameLogicObjectInterface) : GameObject(static_cast<GameLogicObjectInterface*>(gameLogicObjectInterface), GameObjectType::Container)
{
}

Container::~Container()
{
}

void Container::move(Directions direction)
{
	return;
}

void Container::inspect(GameObject* const gameObject)
{
	return;
}

std::string Container::getInfo()
{
	return "Looks like ordinary chest";
}