#include "GameLogic.h"
#include "Global.h"
#include "GameObjectFactory.h"

GameLogic::GameLogic()
{
	_level = nullptr;
	_currentScreen = nullptr;
	_gameRunning = true;
	_alternativeControls = false;
}

GameLogic::~GameLogic()
{
	if (_currentScreen)
	{
		delete _currentScreen;
	}

	if (_level)
	{
		delete _level;
	}

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

void GameLogic::loadLevel(string levelPath)
{
	WRITE_LOG("loading level...");

	if (_level)
	{
		_level->loadLevel(levelPath);
	}
	else
	{
		_level = new Level(this);
		_level->loadLevel(levelPath);
	}

	WRITE_LOG("level loaded");
}

void GameLogic::processInput()
{
	while (_gameRunning)
	{
		resultAction action = _currentScreen->draw();

		if (_level && action._gameState != GameStates::MainMenu && action._gameState != GameStates::GameOver)
		{
			GameObject* gameObject = _level->getObjectNextTo(_level->getPlayer(), action._direction);

			// send event
			_level->getPlayer()->sendEvent(action._event, action._direction, action._data, gameObject);

			if (!_level->getPlayer())
			{
				processState(GameStates::GameOver);
				continue;
			}

			_level->drawMap();
		}

		processState(action._gameState);
	}
}

void GameLogic::moveObject(GameObject* gameObject, Directions direction)
{
	if (_level->canMove(gameObject, direction))
	{
		_level->move(gameObject, direction);

		list<GameObject*> enemies = _level->getGameObjectByType(GameObjectTypes::typeEnemy);

		for each (GameObject* enemy in enemies)
		{
			enemy->getStats()->regenerate();
		}

		_level->getPlayer()->getStats()->regenerate();
	}
}

void GameLogic::processState(GameStates gameState)
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
	Screen* newScreen = nullptr;

	switch (type)
	{
	case mainMenu:
		newScreen = new MainMenuScreen();
		break;
	case gameCommand:
		newScreen = new GameCommandScreen();
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
		if (_currentScreen)
		{
			delete _currentScreen;
		}

		_currentScreen = newScreen;

		if (type == mainMenu)
		{
			if (_level)
			{
				delete _level;
				_level = nullptr;

				CLOSE_LOG_WINDOW;
			}
		}
	}
}

void GameLogic::dead(GameObject* gameObject)
{
	_level->remove(gameObject);
}

void GameLogic::enterDoor(GameObject* gameObject)
{
	Door* door = dynamic_cast<Door*>(gameObject);
	string nextMap = door->getMapName();

	loadLevel(nextMap);
}

void GameLogic::run()
{
	processState(GameStates::MainMenu);
	processInput();
}
