#include "MyGameLogicExample.h"


MyGameLogicExample::MyGameLogicExample()
{
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
