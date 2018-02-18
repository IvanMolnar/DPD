#pragma once

#include "State.h"

class StateUp : public State
{
public:
	StateUp(ObjectCommandInterface* commandInterface);
	~StateUp();

	void onEnter();
	void processState(Events event, Directions direction, GameObject* object, std::string& data);
	void onExit();
	bool canChangeState(State* nextState);
};

