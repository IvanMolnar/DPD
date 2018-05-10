#pragma once

#include "GameLogic.h"

class MyGameLogicExample : public GameLogic
{
public:
	MyGameLogicExample();
	~MyGameLogicExample();

	std::unique_ptr<Display> createDisplay() override;
	std::unique_ptr<MapManager> createMapManager() override;
	std::unique_ptr<GUIManager> createGUIManager() override;

private:
	void processAction(const resultAction& action);
	bool processState(GameStates gameState);
	void setInput(const std::shared_ptr<Input> newInput);
};

