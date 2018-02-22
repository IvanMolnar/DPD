#include "MyGameLogicExample.h"
#include "MyDisplayExample.h"


#include "Container.h"
#include "Door.h"
#include "Enemy.h"
#include "Obstacle.h"
#include "Player.h"


#include "MyFileSystem.h"
#include "MyMapLoader.h"

//test
#include "InputCommand.h"

MyGameLogicExample::MyGameLogicExample()
{
	GameLogic::init(createDisplay(), createMapManager());

	setInput(std::shared_ptr<Input>(new InputCommand()));
	
	_gameObjectFactory->registerInstance<Container>(GameObjectTypes::typeContainer);
	_gameObjectFactory->registerInstance<Door>(GameObjectTypes::typeDoor);
	_gameObjectFactory->registerInstance<Enemy>(GameObjectTypes::typeEnemy);
	_gameObjectFactory->registerInstance<Obstacle>(GameObjectTypes::typeObstacle);
	_gameObjectFactory->registerInstance<Player>(GameObjectTypes::typePlayer);
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
	std::unique_ptr<MapLoader> mapLoader = std::unique_ptr<MyMapLoader>(new MyMapLoader(_gameObjectFactory));

	std::shared_ptr<MyFileSystem> myFileSystem = std::make_shared<MyFileSystem>((std::move(mapLoader)));

	return std::make_unique<MapManager>(myFileSystem);
}

void MyGameLogicExample::processAction(const resultAction& action)
{/*
	if (action._gameState != GameStates::MainMenu && action._gameState != GameStates::GameOver)
	{
		GameObject* gameObject = _level->getObjectNextTo(_level->getPlayer(), action._direction);

		// send event
		_level->getPlayer()->sendEvent(action._event, action._direction, action._data, gameObject);
	}*/
}

bool MyGameLogicExample::processState(GameStates gameState)
{
	return false;
}

void MyGameLogicExample::setInput(const std::shared_ptr<Input> newInput)
{
	_currentInput = newInput;
}