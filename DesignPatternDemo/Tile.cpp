#include "Tile.h"



Tile::Tile(void* gameLogicObjectInterface) : GameObject(static_cast<GameLogicObjectInterface*>(gameLogicObjectInterface), GameObjectType::Tile)
{

}

Tile::~Tile()
{
}

void Tile::move(Directions direction)
{
	return;
}

void Tile::inspect(GameObject* const gameObject)
{
	return;
}

void Tile::open(GameObject* const gameObject)
{
	return;
}

void Tile::dead()
{
	return;
}