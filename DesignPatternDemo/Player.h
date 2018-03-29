#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"


class Player : public GameObject
{
public:
	Player(void* gameLogicInterface);
	~Player();
};

