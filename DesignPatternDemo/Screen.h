#pragma once

#include <string>
#include <list>

#include "Global.h"

using namespace std;

struct resultAction
{
	resultAction(Events event = Events::none, Directions direction = Directions::None, GameStates gameEvent = GameStates::Unchanged)
		: _event(event), _direction(direction), _gameState(gameEvent) {}

	Events _event;
	Directions _direction;
	GameStates _gameState;
	string _data;
};

struct inputAction
{
	inputAction(char charId, string description, Events event = Events::none, Directions direction = Directions::None, GameStates gameEvent = GameStates::Unchanged, int setScreenLevel = 0, int drawScreenLevel = 0, bool multiInput = false)
		: _c(charId), _description(description), _setScreenLevel(setScreenLevel), _drawScreenLevel(drawScreenLevel), _event(event), _direction(direction), _gameEvent(gameEvent), _multiInput(multiInput) {}

	char _c;
	string _description;
	Events _event;
	Directions _direction;
	GameStates _gameEvent;
	int _setScreenLevel;
	int _drawScreenLevel;
	bool _multiInput;
};

class Screen
{
public:
	Screen(screenType st);
	virtual ~Screen();

	resultAction draw();
	screenType getType();

protected:
	void addInputAction(inputAction action);
	void addText(string text, int drawScreenLevel);
	void addPresEnter(GameStates nextGameState);

private:
	screenType _screenType;
	list<inputAction> _inputActions;
	int _screenLevel;
	list<char> _multiInputActions;

	char waitForKeyPress();
};

