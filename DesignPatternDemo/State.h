#pragma once

#include "Global.h"
#include "ObjectCommandInterface.h"

#include <iostream>
#include <string>

class GameObject;

class State
{
public:
	State(ObjectCommandInterface* commandInterface, States state);
	virtual ~State();

	std::string getIdString();
	States getId();

	virtual void onEnter() = 0;
	virtual void processState(Events event, Directions direction, GameObject* object, const std::string& data) = 0;
	virtual void onExit() = 0;
	virtual bool canChangeState(State* state) = 0;

protected:
	ObjectCommandInterface* _owner;

private:
	States _stateID;

};

