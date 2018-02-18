#pragma once
#include "GameObject.h"
class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle();

	void sendEvent(Events event, Directions direction, std::string& data, GameObject* object);

	void move(Directions direction);
	void inspect(GameObject* gameObject);
	void attack(GameObject* target);

	// singnals death
	void dead();

	std::string getInfo();
};

