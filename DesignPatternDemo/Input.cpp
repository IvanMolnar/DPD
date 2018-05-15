#include "Input.h"

#include <sstream>
#include <iostream>

Input::Input()
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

			if (action._input == inputEvent.key.keysym.scancode)
			{
				result._direction = action._direction;
				result._event = action._event;
				break;
			}

		}
	}
	else if (inputEvent.type == SDL_MOUSEBUTTONDOWN)
	{
		result._clicks = inputEvent.button.clicks;
		result._x = inputEvent.button.x;
		result._y = inputEvent.button.y;
	}

	return result;
}

void Input::addInputAction(inputAction action)
{
	_inputActions.push_back(action);
}