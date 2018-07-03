#pragma once

#include "GameObjects\GameObject.h"
#include "Interfaces\GameLogicObjectInterface.h"


class Enemy : public GameObject
{
public:
	Enemy(void* gameLogicObjectInterface);
	~Enemy();

	void inspect(GameObject* const gameObject);

	std::string getInfo();
};

