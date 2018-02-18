#pragma once

#include "MapArea.h"
#include "GameLogicObjectInterface.h"
#include "InputCommand.h"
#include "InputMainMenu.h"
#include "InputGameOver.h"
#include "InputCommandAlt.h"
#include "Display.h"
#include "MapAreaInterface.h"
#include <memory>

class GameLogic : public GameLogicObjectInterface, public MapAreaInterface
{
public:
	GameLogic(const std::shared_ptr<Display>& display);
	virtual ~GameLogic();

	void run();

protected:
	std::unique_ptr<MapArea> _level;
	std::unique_ptr<Input> _currentScreen;
	std::shared_ptr<Display> _display;
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



	std::string getDisplayData();
};

