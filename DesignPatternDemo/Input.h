#pragma once

#include <string>
#include <list>

#include "Global.h"

struct resultAction
{
	resultAction(Events event = Events::none, Directions direction = Directions::None, GameStates gameEvent = GameStates::Unchanged)
		: _event(event), _direction(direction), _gameState(gameEvent) {}

	Events _event;
	Directions _direction;
	GameStates _gameState;
	std::string _data;
};

struct inputAction
{
	inputAction(char charId, std::string description, Events event = Events::none, Directions direction = Directions::None, GameStates gameEvent = GameStates::Unchanged, int setScreenLevel = 0, int drawScreenLevel = 0, bool multiInput = false)
		: _c(charId), _description(description), _setScreenLevel(setScreenLevel), _drawScreenLevel(drawScreenLevel), _event(event), _direction(direction), _gameEvent(gameEvent), _multiInput(multiInput) {}

	unsigned int _c;
	std::string _description;
	Events _event;
	Directions _direction;
	GameStates _gameEvent;
	int _setScreenLevel;
	int _drawScreenLevel;
	bool _multiInput;
};

class Input
{
public:
	Input(screenType st);
	virtual ~Input();

	resultAction handleInput();
	screenType getType();

protected:
	void addInputAction(inputAction action);

private:
	screenType _screenType;
	std::list<inputAction> _inputActions;
	int _screenLevel;
	std::list<char> _multiInputActions;

	virtual unsigned int waitForInput() = 0;
};

