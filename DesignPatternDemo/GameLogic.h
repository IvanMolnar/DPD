#pragma once

#include "MapArea.h"
#include "GameLogicObjectInterface.h"
#include "InputCommand.h"
#include "InputMainMenu.h"
#include "InputGameOver.h"
#include "InputCommandAlt.h"
#include "Display.h"
#include <memory>

class GameLogic : public GameLogicObjectInterface
{
public:
	GameLogic();
	virtual ~GameLogic();

	void run();

protected:
	std::unique_ptr<MapArea> _level;
	std::unique_ptr<Input> _currentScreen;
	std::unique_ptr<Display> _display;
	GameStates _currentState;
	bool _gameRunning;
	bool _alternativeControls;
	
	void startGame();
	void loadLevel(const std::string& levelPath);
	void processInput();
	void moveObject(GameObject* gameObject, Directions direction);
	void internalProcessState(GameStates gameEvent);
	void changeScreen(screenType type);
	void dead(GameObject* gameObject);
	void enterDoor(GameObject* gameObject);
	virtual void processAction(const resultAction& action) = 0;
	virtual bool processState(GameStates gameEvent) = 0;

	// events
	virtual void beforeChangeScreen(const std::shared_ptr<Screen>& currentScreen, const std::shared_ptr<Screen>& newScreen) = 0;
	virtual void afterChangeScreen(const std::shared_ptr<Screen>& oldScreen, const std::shared_ptr<Screen>& newScreen) = 0;
};

