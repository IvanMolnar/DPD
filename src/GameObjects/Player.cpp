#include "Player.h"

Player::Player(void* gameLogicObjectInterface) : GameObject(static_cast<GameLogicObjectInterface*>(gameLogicObjectInterface), GameObjectType::Player)
{
}

Player::~Player()
{
}
