#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"


class Player : public GameObject
{
public:
	Player(GameLogicObjectInterface* gameLogicInterface);
	~Player();


	std::string getInfo();

};

