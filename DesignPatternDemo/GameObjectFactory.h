#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"

#include <map>
#include <memory>


class GameObjectFactory
{
public:
	GameObjectFactory(const GameObjectFactory &old) = delete;
	const GameObjectFactory &operator=(const GameObjectFactory &old) = delete;

	static GameObjectFactory& getInstance()
	{
		static GameObjectFactory instance;
		return instance;
	}

	static void init(std::unique_ptr<GameLogicObjectInterface> gameLogicObjectInterface);

	static std::unique_ptr<GameObject> createGameObject(GameObjectTypes name);

	template<typename T>
	static void registerInstance(GameObjectTypes name);

private:
	GameObjectFactory() {};

	template<typename T>
	static std::unique_ptr<GameObject> createInstance();

	static std::unique_ptr<GameLogicObjectInterface> _gameLogicObjectInterface;
};