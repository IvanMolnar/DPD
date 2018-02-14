#include "Screen.h"

#include <sstream>
#include <iostream>

Screen::Screen(screenType st) : _screenType(st)
{
	_screenLevel = 0;
}

Screen::~Screen()
{
}

resultAction Screen::draw()
{
	resultAction result;

	while (true)
	{
		stringstream ss;

		system("cls");

		for (list<inputAction>::iterator it = _inputActions.begin(); it != _inputActions.end(); it++)
		{
			inputAction action = *it;

			if (action._drawScreenLevel == _screenLevel)
			{
				if (action._c != 1)
				{
					if (action._c != 0)
					{
						ss << action._c << " - " << action._description << endl;
					}
					else
					{
						ss << action._description << endl;
					}
				}
				
			}

		}

		cout << ss.str();

		for (list<inputAction>::iterator it = _inputActions.begin(); it != _inputActions.end(); it++)
		{
			inputAction action = *it;

			if (action._c == 1)
			{
				while (waitForKeyPress() != 13);
				result._gameState = action._gameEvent;
				return result;
			}

		}

		char input = waitForKeyPress();

		for (list<inputAction>::iterator it = _inputActions.begin(); it != _inputActions.end(); it++)
		{
			inputAction action = *it;

			if ((action._drawScreenLevel == _screenLevel) && (action._c == input))
			{
				_screenLevel = action._setScreenLevel;

				if (action._event != Events::none)
				{
					result._event = action._event;
				}

				if (action._direction != Directions::None)
				{
					result._direction = action._direction;
				}

				if (action._gameEvent != GameStates::Unchanged)
				{
					result._gameState = action._gameEvent;
				}

				if (action._setScreenLevel == 0)
				{
					if (!action._multiInput)
					{
						stringstream ss;
						ss << waitForKeyPress();
						result._data = ss.str();
					}
					else
					{
						string response;
						getline(cin, response);
						result._data = response;
					}

					return result;
				}

				break;
			}

		}

	}
}

void Screen::addInputAction(inputAction action)
{
	_inputActions.push_back(action);

	if (action._multiInput)
	{
		_multiInputActions.push_back(action._c);
	}
}

void Screen::addText(string text, int drawScreenLevel)
{
	_inputActions.push_back(inputAction(0, text, Events::none, Directions::None, GameStates::Unchanged, 0, drawScreenLevel));
}

void Screen::addPresEnter(GameStates nextGameState)
{
	_inputActions.push_back(inputAction(1, " ", Events::none, Directions::None, nextGameState, 0, 0));
}

char Screen::waitForKeyPress()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD cNumRead;
	INPUT_RECORD irInBuf[128];

	while (true)
	{
		ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead);  // number of records read

		switch (irInBuf[0].EventType)
		{
		case KEY_EVENT:
			if ((std::find(_multiInputActions.begin(), _multiInputActions.end(), irInBuf[0].Event.KeyEvent.uChar.AsciiChar) != _multiInputActions.end()))
			{
				cout << irInBuf[0].Event.KeyEvent.uChar.AsciiChar;
			}
			
			return irInBuf[0].Event.KeyEvent.uChar.AsciiChar;
		}
	}

	return 0;
}

screenType Screen::getType()
{
	return _screenType;
}
