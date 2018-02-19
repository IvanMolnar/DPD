#pragma once

#include "MapManager.h"
#include "GameLogicObjectInterface.h"
#include "Input.h"
#include "Display.h"
#include "MapAreaInterface.h"
#include <memory>

class GameLogic : public GameLogicObjectInterface, public MapAreaInterface
{
public:
	GameLogic(std::unique_ptr<Display>& display, std::unique_ptr<MapManager>& mapManager);
	virtual ~GameLogic();

	void run();

protected:
	std::shared_ptr<Input> _currentInput;
	std::unique_ptr<Display> _display;
	std::unique_ptr<MapManager> _mapManager;
	GameStates _currentState;
	bool _gameRunning;
	bool _alternativeControls;
	void startGame();
	void loadLevel(const std::string& levelPath);
	void processInput();
	void moveObject(GameObject* gameObject, Directions direction);
	void internalProcessState(GameStates gameEvent);
	void dead(GameObject* gameObject);
	void enterDoor(GameObject* gameObject);
	virtual void processAction(const resultAction& action) = 0;
	virtual bool processState(GameStates gameEvent) = 0;
	virtual void setInput(const std::shared_ptr<Input> newInput) = 0;



	std::string getDisplayData();
};

