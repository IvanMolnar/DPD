#pragma once

#include "State.h"

class StateUp : public State
{
public:
	StateUp(ObjectCommandInterface* commandInterface);
	~StateUp();

	void onEnter();
	void processState(Events event, Directions direction, std::shared_ptr<GameObject> object, const std::string& data) override;
	void onExit();
	bool canChangeState(State* nextState);
};

