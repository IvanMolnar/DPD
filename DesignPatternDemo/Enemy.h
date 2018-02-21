#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"


class Enemy : public GameObject
{
public:
	Enemy(GameLogicObjectInterface* gameLogicObjectInterface);
	~Enemy();

	void move(Directions direction);
	void inspect(GameObject* gameObject);

	std::string getInfo();

	// singnals death
	void dead();

private:
	GameLogicObjectInterface* _gameLogicObjectInterface;
};

