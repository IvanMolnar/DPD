#include "State.h"
#include "GameObject.h"

State::State(ObjectCommandInterface* commandInterface, States state)
{
	_owner = commandInterface;
	_stateID = state;
}

State::~State()
{
}

string State::getIdString()
{
	switch (_stateID)
	{
	case standingUp:
		return "standingUp";
	case sneaking:
		return "crouching";
	case dead:
		return "dead";
	default:
		return "INVALID STATE";
	}
}

States State::getId()
{
	return _stateID;
}

