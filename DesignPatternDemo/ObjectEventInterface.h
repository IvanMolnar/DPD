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

	virtual void sendEvent(Events event, Directions direction, const std::string& data, std::shared_ptr<GameObject> object) = 0;
	virtual void changeState(States state) = 0;
};

