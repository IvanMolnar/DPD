#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"


class Player : public GameObject
{
public:
	Player(GameLogicObjectInterface* gameLogicInterface);
	~Player();

	void move(Directions direction) override;
	void inspect(std::shared_ptr<GameObject> gameObject) override;
	std::string getInfo();

	// opening chest
	void open(std::shared_ptr<GameObject> gameObject) override;

	// singnals death
	void dead() override;

};

