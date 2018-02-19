#include "MyGameLogicExample.h"


//test
#include "InputCommand.h"

MyGameLogicExample::MyGameLogicExample(const std::shared_ptr<Display>& display) :
	GameLogic(display)
{
	setInput(std::shared_ptr<Input>(new InputCommand()));
}

MyGameLogicExample::~MyGameLogicExample()
{
}

void MyGameLogicExample::processAction(const resultAction& action)
{
	if (_level && action._gameState != GameStates::MainMenu && action._gameState != GameStates::GameOver)
	{
		GameObject* gameObject = _level->getObjectNextTo(_level->getPlayer(), action._direction);

		// send event
		_level->getPlayer()->sendEvent(action._event, action._direction, action._data, gameObject);

		if (!_level->getPlayer())
		{
			processState(GameStates::GameOver);
		}
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