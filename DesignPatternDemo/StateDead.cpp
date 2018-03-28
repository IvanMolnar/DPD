#include "StateDead.h"


StateDead::StateDead(ObjectCommandInterface* commandInterface) : State(commandInterface, States::dead)
{
}

StateDead::~StateDead()
{
}

void StateDead::onEnter()
{
	WRITE_LOG("StateDead::onEnter");

	_owner->dead();
}

void StateDead::processState(Events event, Directions direction, GameObject* const object, const std::string& data)
{
	WRITE_LOG("StateDead::processState");
}

void StateDead::onExit()
{
	WRITE_LOG("StateDead::onExit");
}

bool StateDead::canChangeState(State* nextState)
{
	return true;
}