#include "GameLogic.h"
#include "Global.h"
#include "GameObjectFactory.h"

GameLogic::GameLogic()
{
	_gameRunning = true;
	_alternativeControls = false;
}

GameLogic::~GameLogic()
{
	CLOSE_LOG_WINDOW;
}

void GameLogic::startGame()
{
	CREATE_LOG_WINDOW("log");
	WRITE_LOG("startGame called");

	processState(GameStates::Loading);

	loadLevel("TestMap.txt");

	processState(GameStates::GameRunning);
}

void GameLogic::loadLevel(const std::string& levelPath)
{
	WRITE_LOG("loading level...");

	if (_level)
	{
		_level->loadLevel(levelPath);
	}
	else
	{
		_level = std::unique_ptr<MapArea>(new MapArea());
		_level->loadLevel(levelPath);
	}

	WRITE_LOG("level loaded");
}

void GameLogic::processInput()
{
	while (_gameRunning)
	{
		resultAction action = _currentScreen->handleInput();//draw();

	    processAction(action);

		_display->draw();

		bool handledEvent = false;
		
		if (action._gameState != GameStates::Unchanged && _currentState != action._gameState)
		{
			handledEvent = processState(action._gameState);
		}
		
		if (!handledEvent)
		{
			internalProcessState(action._gameState);
		}
		
	}
}

void GameLogic::moveObject(GameObject* gameObject, Directions direction)
{
	if (_level->canMove(gameObject, direction))
	{
		_level->move(gameObject, direction);

		std::list<GameObject*> enemies = _level->getGameObjectByType(GameObjectTypes::typeEnemy);

		for each (GameObject* enemy in enemies)
		{
			enemy->getStats()->regenerate();
		}

		_level->getPlayer()->getStats()->regenerate();
	}
}

void GameLogic::internalProcessState(GameStates gameState)
{
	if (_currentState == gameState)
	{
		return;
	}

	_currentState = gameState;

	switch (_currentState)
	{
	case MainMenu:
		changeScreen(screenType::mainMenu);
		break;
	case NewGame:
		startGame();
		break;
	case NewGameAlt:
		_alternativeControls = true;
		startGame();
		break;
	case Loading:
		break;
	case GameRunning:
		if (!_alternativeControls)
		{
			changeScreen(screenType::gameCommand);
		}
		else
		{
			changeScreen(screenType::gameCommandAlt);
		}
		break;
	case GameOver:
		changeScreen(screenType::gameOver);
		break;
	case ExitGame:
		_gameRunning = false;
		break;
	default:
		break;
	}
}

void GameLogic::changeScreen(screenType type)
{
	std::unique_ptr<Input> newScreen;

	switch (type)
	{
	case mainMenu:
		newScreen = new MainMenuScreen();
		break;
	case gameCommand:
		newScreen = new InputCommandScreen();
		break;
	case gameCommandAlt:
		newScreen = new GameCommandScreenAlt();
		break;
	case gameOver:
		newScreen = new GameOverScreen();
		break;
	}

	

	if (newScreen)
	{
		beforeChangeScreen(_currentScreen, newScreen);

		_currentScreen.reset();
		_currentScreen = std::move(newScreen);

		if (type == mainMenu)
		{
			if (_level)
			{
				_level.reset();
				CLOSE_LOG_WINDOW;
			}
		}

		afterChangeScreen(_currentScreen, newScreen);
	}
}

void GameLogic::dead(GameObject* gameObject)
{
	_level->remove(gameObject);
}

void GameLogic::enterDoor(GameObject* gameObject)
{
	Door* door = dynamic_cast<Door*>(gameObject);
	std::string nextMap = door->getMapName();

	loadLevel(nextMap);
}

void GameLogic::run()
{
	_display = std::unique_ptr<Display>(new Display(_level.get()));
	_display->start();
	processState(GameStates::MainMenu);
	processInput();
}
