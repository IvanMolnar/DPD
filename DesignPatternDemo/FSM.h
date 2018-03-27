#pragma once

#include "State.h"
#include <iostream>
#include <string>

class CCharacter;

class FSM
{
public:
	FSM(State* initialState);
	~FSM();

	void changeState(State* state);
	void processCurrentState(Events event, Directions direction, std::shared_ptr<GameObject> object, const std::string& data);

	States getCurrentState();
	std::string getCurrentStateString();

private:
	State* _currentState;
};