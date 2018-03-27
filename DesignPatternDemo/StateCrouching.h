#pragma once

#include "State.h"

class StateCrouching : public State
{
public:
	StateCrouching(ObjectCommandInterface* commandInterface);
	~StateCrouching();

	void onEnter();
	void processState(Events event, Directions direction, std::shared_ptr<GameObject> object, const std::string& data) override;
	void onExit();
	bool canChangeState(State* nextState);
};

