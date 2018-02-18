#pragma once

#include "GameObject.h"

class Door : public GameObject
{
public:
	Door();
	~Door();

	void move(Directions direction);
	void inspect(GameObject* gameObject);
	void open(GameObject* gameObject);
	void dead();

	std::string getMapName();

	std::string getInfo();
};
