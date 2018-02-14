#include "FSM.h"

FSM::FSM(State* initialState)
{
	_currentState = initialState;
}

FSM::~FSM()
{
	delete _currentState;
}

void FSM::changeState(State* state)
{
	if (_currentState->getId() == state->getId())
	{
		WRITE_LOG("Can't switch to same state");
		delete state;
		return;
	}

	if (_currentState->canChangeState(state))
	{
		WRITE_LOG("Changing state from " + _currentState->getIdString() + " to " + state->getIdString());

		_currentState->onExit();
		delete _currentState;
		_currentState = state;
		_currentState->onEnter();
	}
	else
	{
		WRITE_LOG("Could not change state from " + _currentState->getIdString() + " to " + state->getIdString());
		delete state;
	}
}

void FSM::processCurrentState(Events event, Directions direction, GameObject* object, string& data)
{
	WRITE_LOG("processing state for " + _currentState->getIdString() + " state");
	_currentState->processState(event, direction, object, data);
}

States FSM::getCurrentState()
{
	return _currentState->getId();
}

string FSM::getCurrentStateString()
{
	return _currentState->getIdString();
}