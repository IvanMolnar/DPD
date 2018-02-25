#pragma once

#include "GameObjectFactory.h"


void GameObjectFactory::init(GameLogicObjectInterface* gameLogicObjectInterface)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

std::unique_ptr<GameObject> GameObjectFactory::createGameObject(GameObjectType name)
{
	return _registeredGameObjects[name](_gameLogicObjectInterface);
}