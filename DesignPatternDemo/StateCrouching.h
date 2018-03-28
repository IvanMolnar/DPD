#pragma once

#include "State.h"

class StateCrouching : public State
{
public:
	StateCrouching(ObjectCommandInterface* commandInterface);
	~StateCrouching();

	void onEnter();
	void processState(Events event, Directions direction, const GameObject* const object, const std::string& data) override;
	void onExit();
	bool canChangeState(State* nextState);
};

