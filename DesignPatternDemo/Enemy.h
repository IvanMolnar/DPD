#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"


class Enemy : public GameObject
{
public:
	Enemy(GameLogicObjectInterface* gameLogicObjectInterface);
	~Enemy();

	void inspect(const GameObject* const gameObject);

	std::string getInfo();


private:
	GameLogicObjectInterface* _gameLogicObjectInterface;
};

