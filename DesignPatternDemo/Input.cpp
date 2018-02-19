#include "Input.h"

#include <sstream>
#include <iostream>

Input::Input() :
	_inputLevel(0)
{
}

Input::~Input()
{
}

resultAction Input::handleInput()
{
	resultAction result;

	unsigned long input = waitForInput();

	for (std::list<inputAction>::iterator it = _inputActions.begin(); it != _inputActions.end(); it++)
	{
		inputAction action = *it;

		if ((action._inputLevel == _inputLevel) && (action._input == input))
		{
			_inputLevel = action._setInputLevel;

			result._direction = action._direction;
			result._event = action._event;
			result._gameState = action._gameEvent;
			break;
		}

	}

	return result;
}

void Input::addInputAction(inputAction action)
{
	_inputActions.push_back(action);

	if (action._multiInput)
	{
		_multiInputActions.push_back(action._input);
	}
}