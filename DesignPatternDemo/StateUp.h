#pragma once

#include "State.h"

class StateUp : public State
{
public:
	StateUp(ObjectCommandInterface* commandInterface);
	~StateUp();

	void onEnter();
	void processState(Events event, Directions direction, const GameObject * const object, const std::string& data) override;
	void onExit();
	bool canChangeState(State* nextState);
};

