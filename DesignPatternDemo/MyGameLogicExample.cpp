#include "MyGameLogicExample.h"
#include "MyDisplayExample.h"

//test
#include "InputCommand.h"

MyGameLogicExample::MyGameLogicExample()
{
	GameLogic::init(createDisplay(), createMapManager());

	setInput(std::shared_ptr<Input>(new InputCommand()));
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
	return std::unique_ptr<MapManager>(new MapManager());
}

void MyGameLogicExample::processAction(const resultAction& action)
{
	if (_level && action._gameState != GameStates::MainMenu && action._gameState != GameStates::GameOver)
	{
		GameObject* gameObject = _level->getObjectNextTo(_level->getPlayer(), action._direction);

		// send event
		_level->getPlayer()->sendEvent(action._event, action._direction, action._data, gameObject);
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