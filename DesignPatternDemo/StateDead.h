#pragma once

#include "State.h"

class StateDead : public State
{
public:
	StateDead(ObjectCommandInterface* commandInterface);
	~StateDead();

	void onEnter();
	void processState(Events event, Directions direction, GameObject* object, std::string& data);
	void onExit();
	bool canChangeState(State* nextState);
};

