#pragma once

#include "GameObjectFactory.h"

static std::map<GameObjectTypes, std::unique_ptr<GameObject>(*)()> _registeredGameObjects;

void GameObjectFactory::init(GameLogicObjectInterface* gameLogicObjectInterface)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

template<typename T>
void GameObjectFactory::registerInstance(GameObjectTypes name)
{
	_registeredGameObjects[name] = &createInstance<T>;
}

std::unique_ptr<GameObject> GameObjectFactory::createGameObject(GameObjectTypes name)
{
	return _registeredGameObjects[name]();
}

template<typename T>
std::unique_ptr<GameObject> GameObjectFactory::createInstance()
{
	return std::make_unique<T>();
}