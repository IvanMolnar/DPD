#pragma once

#include "Player.h"
#include "Obstacle.h"
#include "Enemy.h"
#include "Container.h"
#include "Door.h"

#include "Sword.h"
#include "Armor.h"

#include <map>

using namespace std;

static GameLogicObjectInterface* _gameLogicObjectInterface;

class GameObjectFactory
{
public:
	static GameObjectFactory& getInstance()
	{
		static GameObjectFactory instance;
		return instance;
	}

	static void init(GameLogicObjectInterface* gameLogicObjectInterface);
	static char getCharIdFromType(GameObjectTypes gameObjectType);
	static GameObject* createGameObject(char c);

private:
	GameObjectFactory() {}
	GameObjectFactory(const GameObjectFactory &old);
	const GameObjectFactory &operator=(const GameObjectFactory &old);
	~GameObjectFactory() {}
};

