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
		WRITE_LOG_MESSAGE("Can't switch to same state");
		delete state;
		return;
	}

	if (_currentState->canChangeState(state))
	{
		WRITE_LOG_MESSAGE("Changing state from " + _currentState->getIdString() + " to " + state->getIdString());

		_currentState->onExit();
		delete _currentState;
		_currentState = state;
		_currentState->onEnter();
	}
	else
	{
		WRITE_LOG_MESSAGE("Could not change state from " + _currentState->getIdString() + " to " + state->getIdString());
		delete state;
	}
}

void FSM::processCurrentState(Events event, Directions direction, GameObject* const object, const std::string& data)
{
	WRITE_LOG_MESSAGE("processing state for " + _currentState->getIdString() + " state");
	_currentState->processState(event, direction, object, data);
}

States FSM::getCurrentState()
{
	return _currentState->getId();
}

std::string FSM::getCurrentStateString()
{
	return _currentState->getIdString();
}