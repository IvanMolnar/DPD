#pragma once

#include "State.h"

class StateDead : public State
{
public:
	StateDead(ObjectCommandInterface* commandInterface);
	~StateDead();

	void onEnter();
	void processState(Events event, Directions direction, const GameObject* const object, const std::string& data) override;
	void onExit();
	bool canChangeState(State* nextState);
};

