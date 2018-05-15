#include "GameLogic.h"
#include "Global.h"
#include "InventoryManager.h"

const static std::string __namespace__ = "GameLogic";

GameLogic::GameLogic()
{
	_gameRunning = true;
}

void GameLogic::init(std::unique_ptr<Display>&& display, std::unique_ptr<MapManager>&& mapManager, std::unique_ptr<GUIManager>&& guiManager)
{
	LOG_INIT;

	_display = std::move(display);
	_mapManager = std::move(mapManager);
	_guiManager = std::move(guiManager);
	
	GameObjectFactory::getInstance()->setCallbackInterface(this);
}

GameLogic::~GameLogic()
{
}

void GameLogic::startGame()
{
	WRITE_LOG_MESSAGE("startGame called");

	processState(GameStates::Loading);

	std::string guiFilePath = "GUI.ini";
	_guiManager->loadGUI(guiFilePath);
	loadLevel("TestMap.ini");

	processState(GameStates::GameRunning);
}

void GameLogic::loadLevel(const std::string& levelPath)
{
	WRITE_LOG_MESSAGE("loading level...");

	_mapManager->loadArea(levelPath);
	std::vector<MyObjectDisplayData*> loadedObjects = _mapManager->getCurrentMapArea()->getDisplayData();
	_display->initObjects(&loadedObjects);
	_display->loadTexture(&loadedObjects);
	_display->addObjectsToRender(&loadedObjects);

	std::vector<MyObjectDisplayData*> loadedGUI = _guiManager->getDisplayData();
	_display->initObjects(&loadedGUI);
	_display->loadTexture(&loadedGUI);
	_display->addObjectsToRender(&loadedGUI);

	WRITE_LOG_MESSAGE("level loaded");
}

void GameLogic::processInput()
{
	while (_gameRunning)
	{
		resultAction action = _currentInput->handleInput();

		if (action._event != Events::none)
		{
			processAction(action);
		}
		else if (action._clicks > 0 )
		{
			_guiManager->processMouseEvent(action._clicks, action._x, action._y);
		}

		//internalProcessState(action._gameState);

		_display->draw();
	}
}

void GameLogic::moveObject(GameObject* const gameObject, Directions direction)
{/*
	if (_level->canMove(gameObject, direction))
	{
		_level->move(gameObject, direction);

		std::list<GameObject*> enemies = _level->getGameObjectByType(GameObjectType::Enemy);

		for each (GameObject* enemy in enemies)
		{
			enemy->getStats()->regenerate();
		}

		_level->getPlayer()->getStats()->regenerate();
	}*/
	if (_mapManager->getCurrentMapArea()->canMove(gameObject, direction))
	{
		_mapManager->getCurrentMapArea()->move(gameObject, direction);
	}
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
	case GameStates::MainMenu:
		break;
	case GameStates::NewGame:
		startGame();
		break;
	case GameStates::Loading:
		break;
	case GameStates::GameRunning:
		break;
	case GameStates::GameOver:
		break;
	case GameStates::ExitGame:
		_gameRunning = false;
		break;
	default:
		break;
	}
}

void GameLogic::dead(GameObject* const gameObject)
{
	//_level->remove(gameObject);
}

void GameLogic::enterDoor(GameObject* const gameObject)
{
//	Door* door = dynamic_cast<Door*>(gameObject);
//	std::string nextMap = door->getMapName();

//	loadLevel(nextMap);
}

std::vector<MyObjectDisplayData*> GameLogic::getDisplayData()
{
	return _mapManager->getCurrentMapArea()->getDisplayData();
	std::vector<MyObjectDisplayData*> a;
	 a;//_mapManager->getCurrentMapArea()->getLevelDisplayData();
}

void GameLogic::run()
{
	_display->init(this);
	_display->start();
	internalProcessState(GameStates::NewGame);
	processInput();
}

void GameLogic::inspect(GameObject* const gameObject)
{

}

void GameLogic::attack(GameObject* const gameObject, EquipSlot* const equipSlot)
{

}

void GameLogic::open(GameObject* const gameObject)
{

}