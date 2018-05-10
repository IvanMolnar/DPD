#include "MyGameLogicExample.h"
#include "MyDisplayExample.h"

#include "Container.h"
#include "Door.h"
#include "Enemy.h"
#include "Obstacle.h"
#include "Player.h"
#include "Tile.h"


#include "MyFileSystem.h"
#include "MyMapLoader.h"
#include "MyGUIManager.h"

//test
#include "MyInputExample.h"

MyGameLogicExample::MyGameLogicExample()
{
	GameLogic::init(createDisplay(), createMapManager(), createGUIManager());

	setInput(std::shared_ptr<Input>(new MyInputExample()));
	
	_currentInput->init();

	GameObjectFactory::getInstance()->registerInstance<Container>(GameObjectType::Container);
	GameObjectFactory::getInstance()->registerInstance<Door>(GameObjectType::Door);
	GameObjectFactory::getInstance()->registerInstance<Enemy>(GameObjectType::Enemy);
	GameObjectFactory::getInstance()->registerInstance<Obstacle>(GameObjectType::Obstacle);
	GameObjectFactory::getInstance()->registerInstance<Player>(GameObjectType::Player);
	GameObjectFactory::getInstance()->registerInstance<Tile>(GameObjectType::Tile);
}

MyGameLogicExample::~MyGameLogicExample()
{
}

std::unique_ptr<Display> MyGameLogicExample::createDisplay()
{
	return std::unique_ptr<Display>(new MyDisplayExample());
}

std::unique_ptr<MapManager> MyGameLogicExample::createMapManager()
{
	std::unique_ptr<MapLoader> mapLoader = std::unique_ptr<MyMapLoader>(new MyMapLoader());

	std::shared_ptr<FileSystem> myFileSystem = std::make_shared<MyFileSystem>((std::move(mapLoader)));

	return std::make_unique<MapManager>(myFileSystem);
}

std::unique_ptr<GUIManager> MyGameLogicExample::createGUIManager()
{
	return std::unique_ptr<GUIManager>(new MyGUIManager());
}

void MyGameLogicExample::processAction(const resultAction& action)
{/*
	if (action._gameState != GameStates::MainMenu && action._gameState != GameStates::GameOver)
	{
		GameObject* gameObject = _level->getObjectNextTo(_level->getPlayer(), action._direction);

		// send event
		_level->getPlayer()->sendEvent(action._event, action._direction, action._data, gameObject);
	}*/


	if (action._event != Events::none)
	{
		_mapManager->getCurrentMapArea()->getPlayer()->sendEvent(action._event, action._direction, action._data, nullptr);
	}
}

bool MyGameLogicExample::processState(GameStates gameState)
{
	return false;
}

void MyGameLogicExample::setInput(const std::shared_ptr<Input> newInput)
{
	_currentInput = newInput;
}