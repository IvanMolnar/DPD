#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"

#include <map>
#include <memory>

static std::map<GameObjectTypes, std::unique_ptr<GameObject>(*)()> _registeredGameObjects;
static GameLogicObjectInterface* _gameLogicObjectInterface;

class GameObjectFactory
{
public:/*
	GameObjectFactory(GameObjectFactory const&) = delete;             // Copy construct
	GameObjectFactory(GameObjectFactory&&) = delete;                  // Move construct
	GameObjectFactory& operator=(GameObjectFactory const&) = delete;  // Copy assign
	GameObjectFactory& operator=(GameObjectFactory &&) = delete;      // Move assign
	
	static GameObjectFactory& getInstance()
	{
		static GameObjectFactory instance;
		return instance;
	}*/

	void init(GameLogicObjectInterface* gameLogicObjectInterface);

	std::unique_ptr<GameObject> createGameObject(GameObjectTypes name);

	template<typename T>
	static std::unique_ptr<GameObject> createInstance()
	{
		return std::make_unique<T>(_gameLogicObjectInterface);
	}

	template<typename T>
	void registerInstance(GameObjectTypes name)
	{
		_registeredGameObjects[name] = &createInstance<T>;
	}

private:
	

	
	
};