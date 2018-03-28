#pragma once

#include "Global.h"

#include <string>
#include <memory>

class GameObject;

class ObjectEventInterface
{
public:
	ObjectEventInterface() {};
	~ObjectEventInterface() {};

	virtual void sendEvent(Events event, Directions direction, const std::string& data, GameObject* const object) = 0;
	virtual void changeState(States state) = 0;
};

