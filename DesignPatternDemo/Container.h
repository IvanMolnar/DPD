#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"

class Container : public GameObject
{
public:
	Container(GameLogicObjectInterface* gameLogicObjectInterface);
	~Container();

	void move(Directions direction);
	void inspect(std::shared_ptr<GameObject> gameObject);
	std::string getInfo();

	// singnals death
	void dead();

private:
	GameLogicObjectInterface* _gameLogicObjectInterface;
};
