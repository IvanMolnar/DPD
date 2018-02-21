#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"


class Player : public GameObject
{
public:
	Player(GameLogicObjectInterface* gameLogicInterface);
	~Player();

	void move(Directions direction);
	void inspect(GameObject* gameObject);
	std::string getInfo();

	// opening chest
	void open(GameObject* gameObject);

	// singnals death
	void dead();

};

