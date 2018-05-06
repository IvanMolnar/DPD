#pragma once

#include "GameObject.h"

class Tile : public GameObject
{
public:
	Tile(void* gameLogicInterface);
	~Tile();

	void move(Directions direction);
	void inspect(GameObject* const gameObject);
	void open(GameObject* const gameObject);
	void dead();
};

