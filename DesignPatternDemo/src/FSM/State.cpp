#include "FSM\State.h"
#include "GameObjects\GameObject.h"

State::State(ObjectCommandInterface* commandInterface, States state)
{
	_owner = commandInterface;
	_stateID = state;
}

State::~State()
{
}

std::string State::getIdString()
{
	switch (_stateID)
	{
	case States::standingUp:
		return "standingUp";
	case States::sneaking:
		return "crouching";
	case States::dead:
		return "dead";
	default:
		return "INVALID STATE";
	}
}

States State::getId()
{
	return _stateID;
}

