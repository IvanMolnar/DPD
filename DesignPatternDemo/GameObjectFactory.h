#pragma once

#include "GameObject.h"

#include <map>
#include <memory>

static std::map<GameObjectTypes, std::unique_ptr<GameObject>(*)()> _registeredGameObjects;
static GameLogicObjectInterface* _gameLogicObjectInterface;

class GameObjectFactory
{
public:

	GameObjectFactory(const GameObjectFactory&) = delete; // Prevent construction by copying
	GameObjectFactory& operator=(const GameObjectFactory&) = delete; // Prevent assignment
	GameObjectFactory& operator=(GameObjectFactory&&) = delete;

	GameObjectFactory()
	{

	}

	static std::shared_ptr<GameObjectFactory> getInstance()
	{
		static std::shared_ptr<GameObjectFactory> _instance;

		if (!_instance)
		{
			_instance = std::make_shared<GameObjectFactory>();
		}

		return _instance;
	}

	void init(GameLogicObjectInterface* gameLogicObjectInterface);

	std::unique_ptr<GameObject> createGameObject(GameObjectTypes name);

	
	template<typename T>
	void registerInstance(GameObjectTypes name)
	{
		_registeredGameObjects[name] = &createInstance<T>;
	}

private:

	template<typename T>
	static std::unique_ptr<GameObject> createInstance()
	{
		return std::make_unique<T>(_gameLogicObjectInterface);
	}
	
	
};