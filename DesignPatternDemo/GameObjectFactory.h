#pragma once

#include "GameObject.h"

#include <map>
#include <memory>
#include <functional>

template<typename T>
std::unique_ptr<GameObject> createInstance(GameLogicObjectInterface* gameLogicObjectInterface)
{
	return std::make_unique<T>(gameLogicObjectInterface);
}

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

	std::unique_ptr<GameObject> createGameObject(GameObjectType name);

	template<typename T>
	void registerInstance(GameObjectType name)
	{
		_registeredGameObjects[name] = &createInstance<T>;
	}

private:
	std::map<GameObjectType, std::function<std::unique_ptr<GameObject>(GameLogicObjectInterface*)>> _registeredGameObjects;
	GameLogicObjectInterface* _gameLogicObjectInterface;
};