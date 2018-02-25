#include "StateCrouching.h"
#include "GameObject.h"


StateCrouching::StateCrouching(ObjectCommandInterface* commandInterface) : State(commandInterface, States::sneaking)
{
}

StateCrouching::~StateCrouching()
{
}

void StateCrouching::onEnter()
{
	WRITE_LOG("StateCrouching::onEnter");
}

void StateCrouching::processState(Events event, Directions direction, GameObject* object, const std::string& data)
{
	WRITE_LOG("StateCrouching::processState");

	switch (event)
	{
	case Events::walk:
		_owner->move(direction);
		break;
	case Events::inspect:
		WRITE_LOG_GAME("Can't inspect while crouching");
		break;
	case Events::attack:
		if (object)
		{
			_owner->attack(object);
		}
		break;
	case Events::interact:
		if (object)
		{
			if (object->getType() == GameObjectType::Container)
			{
				_owner->open(object);
			}
		}
		break;
	case Events::equip:
		WRITE_LOG_GAME("Can't equip while crouching");
		break;
	case Events::sneak:
		// we are allready in sneak state
		break;
	case Events::standUp:
		_owner->changeState(States::standingUp);
		break;
	default:
//		WRITE_LOG("unhandled event " + event);
		break;
	}
}

void StateCrouching::onExit()
{
	WRITE_LOG("StateCrouching::onExit");
}

bool StateCrouching::canChangeState(State* nextState)
{
	return true;
}