#pragma once

#include "GameObjects\GameObject.h"
#include "Interfaces\GameLogicObjectInterface.h"


class Player : public GameObject
{
public:
	Player(void* gameLogicInterface);
	~Player();
};

