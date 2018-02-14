#pragma once

#include "Global.h"

#include <string>

class GameObject;

class ObjectEventInterface
{
public:
	ObjectEventInterface() {};
	~ObjectEventInterface() {};

	virtual void sendEvent(Events event, Directions direction, std::string& data, GameObject* object) = 0;
	virtual void changeState(States state) = 0;
};

