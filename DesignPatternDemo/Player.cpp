#include "Player.h"

Player::Player(GameLogicObjectInterface* gameLogicObjectInterface) : GameObject(GameObjectType::Player)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

Player::~Player()
{
}
