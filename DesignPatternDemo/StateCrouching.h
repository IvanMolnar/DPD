#pragma once

#include "State.h"

class StateCrouching : public State
{
public:
	StateCrouching(ObjectCommandInterface* commandInterface);
	~StateCrouching();

	void onEnter();
	void processState(Events event, Directions direction, GameObject* object, string& data);
	void onExit();
	bool canChangeState(State* nextState);
};

