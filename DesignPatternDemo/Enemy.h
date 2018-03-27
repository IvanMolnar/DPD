#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"


class Enemy : public GameObject
{
public:
	Enemy(GameLogicObjectInterface* gameLogicObjectInterface);
	~Enemy();

	void inspect(std::shared_ptr<GameObject> gameObject);

	std::string getInfo();


private:
	GameLogicObjectInterface* _gameLogicObjectInterface;
};

