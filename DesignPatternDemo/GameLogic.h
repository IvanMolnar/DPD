#pragma once

#include "Level.h"
#include "GameLogicObjectInterface.h"
#include "GameCommandScreen.h"
#include "MainMenuScreen.h"
#include "GameOverScreen.h"
#include "GameCommandScreenAlt.h"

class GameLogic : public GameLogicObjectInterface
{
public:
	GameLogic();
	~GameLogic();

	void run();

private:
	Level* _level;
	Screen* _currentScreen;
	GameStates _currentState;
	bool _gameRunning;
	bool _alternativeControls;
	
	void startGame();
	void loadLevel(string levelPath);
	void processInput();
	void moveObject(GameObject* gameObject, Directions direction);
	void processState(GameStates gameEvent);
	void changeScreen(screenType type);
	void dead(GameObject* gameObject);
	void enterDoor(GameObject* gameObject);
};

