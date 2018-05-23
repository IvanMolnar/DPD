#include "FSM\StateUp.h"
#include "GameObjects\GameObject.h"

StateUp::StateUp(ObjectCommandInterface* commandInterface) : State(commandInterface, States::standingUp)
{
}

StateUp::~StateUp()
{
}

void StateUp::onEnter()
{
	WRITE_LOG_MESSAGE("StateUp::onEnter");
}

void StateUp::processState(Events event, Directions direction, GameObject* const object, const std::string& data)
{
	WRITE_LOG_MESSAGE("StateUp::processState");

	switch (event)
	{
	case Events::walk:
		_owner->move(direction);
		break;
	case Events::inspect:
		if (object)
		{
			_owner->inspect(object);
		}
		break;
	case Events::attack:
		if (object)
		{
//			_owner->attack(object);
		}
		break;
	case Events::interact:
		if (object)
		{
			_owner->open(object);
		}
		break;
	case Events::equip:
		if (data.length() == 2)
		{
			_owner->equip(data.at(0) - '0', data.at(1) - '0');
		}
		break;
	case Events::sneak:
		_owner->changeState(States::sneaking);
		break;
	case Events::standUp:
		// we are allready standing up
		break;
	default:
	//	WRITE_LOG("unhandled event " + event);
		break;
	}
}

void StateUp::onExit()
{
	WRITE_LOG_MESSAGE("StateUp::onExit");
}

bool StateUp::canChangeState(State* nextState)
{
	return true;
}