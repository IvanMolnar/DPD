#pragma once

#include <string>
#include <list>

#include "Global.h"

#include "../../2D_Engine/2D_Engine/InputInterface.h"

struct resultAction
{
	resultAction(Events event = Events::none, Directions direction = Directions::None, GameStates gameEvent = GameStates::Unchanged)
		: _event(event), _direction(direction), _clicks(0), _x(0), _y(0) {}

	Events _event;
	Directions _direction;
	std::string _data;

	// mouse
	unsigned char _clicks;       /**< 1 for single-click, 2 for double-click, etc. */
	int _x;           /**< X coordinate, relative to window */
	int _y;           /**< Y coordinate, relative to window */
};

struct inputAction
{
	inputAction(unsigned int charId, Events event = Events::none, Directions direction = Directions::None)
		: _input(charId), _event(event), _direction(direction) {}

	unsigned int _input;
	Events _event;
	Directions _direction;
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

	virtual SDL_Event* waitForInput() = 0;
};

