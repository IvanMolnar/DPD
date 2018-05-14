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

	SDL_Event inputEvent = *waitForInput();

	if (inputEvent.type == SDL_KEYDOWN)
	{
		for (std::list<inputAction>::iterator it = _inputActions.begin(); it != _inputActions.end(); it++)
		{
			inputAction action = *it;

			if ((action._inputLevel == _inputLevel) && (action._input == inputEvent.key.keysym.scancode))
			{
				_inputLevel = action._setInputLevel;

				result._direction = action._direction;
				result._event = action._event;
				result._gameState = action._gameEvent;
				break;
			}

		}
	}
	else if (inputEvent.type == SDL_MOUSEBUTTONDOWN)
	{
	    //event.button;
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