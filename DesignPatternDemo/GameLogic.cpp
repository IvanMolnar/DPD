#include "GameLogic.h"
#include "Global.h"

GameLogic::GameLogic()
{
	_gameRunning = true;
}

void GameLogic::init(std::unique_ptr<Display>& display, std::unique_ptr<MapManager>& mapManager)
{
	_display = std::move(display);
	_mapManager = std::move(mapManager);
	
	GameObjectFactory::getInstance()->init(this);
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

	_mapManager->loadArea(levelPath);
	//_mapManager->setCurrentMapArea()

	WRITE_LOG("level loaded");
}

void GameLogic::processInput()
{
	while (_gameRunning)
	{
		resultAction action = _currentInput->handleInput();

	    processAction(action);

		internalProcessState(action._gameState);

		_display->draw();
	}
}

void GameLogic::moveObject(GameObject* gameObject, Directions direction)
{/*
	if (_level->canMove(gameObject, direction))
	{
		_level->move(gameObject, direction);

		std::list<GameObject*> enemies = _level->getGameObjectByType(GameObjectTypes::typeEnemy);

		for each (GameObject* enemy in enemies)
		{
			enemy->getStats()->regenerate();
		}

		_level->getPlayer()->getStats()->regenerate();
	}*/
}

void GameLogic::internalProcessState(GameStates gameState)
{
	if (_currentState == gameState || _currentState == GameStates::Unchanged)
	{
		return;
	}

	bool handledEvent = processState(gameState);

	if (handledEvent)
	{
		return;
	}

	_currentState = gameState;

	switch (_currentState)
	{
	case MainMenu:
		break;
	case NewGame:
		startGame();
		break;
	case Loading:
		break;
	case GameRunning:
		break;
	case GameOver:
		break;
	case ExitGame:
		_gameRunning = false;
		break;
	default:
		break;
	}
}

void GameLogic::dead(GameObject* gameObject)
{
	//_level->remove(gameObject);
}

void GameLogic::enterDoor(GameObject* gameObject)
{
//	Door* door = dynamic_cast<Door*>(gameObject);
//	std::string nextMap = door->getMapName();

//	loadLevel(nextMap);
}

std::string GameLogic::getDisplayData()
{
	return std::string();
}

void GameLogic::run()
{
	_display->init(this);
	_display->start();
	internalProcessState(GameStates::NewGame);
	processInput();
}
