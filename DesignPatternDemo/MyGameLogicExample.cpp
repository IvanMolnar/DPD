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
	
	GameObjectFactory::getInstance()->registerInstance<Container>(GameObjectTypes::typeContainer);
	GameObjectFactory::getInstance()->registerInstance<Door>(GameObjectTypes::typeDoor);
	GameObjectFactory::getInstance()->registerInstance<Enemy>(GameObjectTypes::typeEnemy);
	GameObjectFactory::getInstance()->registerInstance<Obstacle>(GameObjectTypes::typeObstacle);
	GameObjectFactory::getInstance()->registerInstance<Player>(GameObjectTypes::typePlayer);
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