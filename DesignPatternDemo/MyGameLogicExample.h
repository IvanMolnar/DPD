#pragma once

#include "GameLogic.h"

class MyGameLogicExample : public GameLogic
{
public:
	MyGameLogicExample(const std::shared_ptr<Display>& display);
	~MyGameLogicExample();

private:
	void processAction(const resultAction& action);
	bool processState(GameStates gameState);
};

