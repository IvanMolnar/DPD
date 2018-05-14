#pragma once

#include <string>
#include <list>

#include "Global.h"

#include "../../2D_Engine/2D_Engine/InputInterface.h"

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
		: _input(charId), _description(description), _setInputLevel(setScreenLevel), _inputLevel(drawScreenLevel), _event(event), _direction(direction), _gameEvent(gameEvent), _multiInput(multiInput) {}

	unsigned int _input;
	std::string _description;
	Events _event;
	Directions _direction;
	GameStates _gameEvent;
	int _setInputLevel;
	int _inputLevel;
	bool _multiInput;
};

class Input
{
public:
	Input();
	virtual ~Input();

	virtual void init() = 0;

	resultAction handleInput();

protected:
	void addInputAction(inputAction action);

private:
	std::list<inputAction> _inputActions;
	int _inputLevel;
	std::list<char> _multiInputActions;

	virtual SDL_Event* waitForInput() = 0;
};

