#pragma once

#include "GameLogic.h"

class MyGameLogicExample : public GameLogic
{
public:
	MyGameLogicExample();
	~MyGameLogicExample();

private:
	void processAction(const resultAction& action);
	bool processState(GameStates gameState);
};

