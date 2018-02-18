#pragma once

#include "GameObjectFactory.h"

static std::map<GameObjectTypes, char> _charTypeMap;

void GameObjectFactory::init(GameLogicObjectInterface* gameLogicObjectInterface)
{
	_gameLogicObjectInterface = gameLogicObjectInterface;
}

char GameObjectFactory::getCharIdFromType(GameObjectTypes gameObjectType)
{
	return _charTypeMap[gameObjectType];
}

GameObject* GameObjectFactory::createGameObject(char c)
{
	GameObject* result = nullptr;
/*
	switch (c)
	{
	case '#':
		result = new Obstacle();
		break;
	case 'x':
		result = new Player(_gameLogicObjectInterface);
		break;
	case 'e':
		result = new Enemy(_gameLogicObjectInterface);
		break;
	case 'c':
		result = new Container(_gameLogicObjectInterface);
		break;
	case 'd':
		result = new Door();
		break;
	}*/

	if (result)
	{
		_charTypeMap[result->getType()] = c;
	}
	
	return result;
}