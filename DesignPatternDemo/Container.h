#pragma once

#include "GameObject.h"
#include "GameLogicObjectInterface.h"

class Container : public GameObject
{
public:
	Container(GameLogicObjectInterface* gameLogicObjectInterface);
	~Container();

	void move(Directions direction);
	void inspect(GameObject* const gameObject);
	std::string getInfo();

private:
	GameLogicObjectInterface* _gameLogicObjectInterface;
};
