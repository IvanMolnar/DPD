#include "GameObject.h"
#include "StateUp.h"
#include "StateCrouching.h"
#include "StateDead.h"

#include <sstream>

const static std::string __namespace__ = "GameObject";

GameObject::GameObject(GameLogicObjectInterface* gameLogicObjectInterface, GameObjectType type) : _type(type)
{
	_drawLayer = DrawingLayer::Game;

	_gameLogicObjectInterface = static_cast<GameLogicObjectInterface*>(gameLogicObjectInterface);
	_FSM = std::make_unique<FSM>(new StateUp(this));
	_inventoryManager = std::make_unique<InventoryManager>();

	_stats = std::make_shared<GameObjectStats>(this);
}

GameObject::~GameObject()
{

}

void GameObject::sendEvent(Events event, Directions direction, const std::string& data, GameObject* const object)
{
	_FSM->processCurrentState(event, direction, object, data);
}

void GameObject::changeState(States state)
{
	State* newState = nullptr;

	switch (state)
	{
	case States::standingUp:
		newState = new StateUp(this);
		break;
	case States::sneaking:
		newState = new StateCrouching(this);
		break;
	case States::dead:
		newState = new StateDead(this);
		break;
	default:
		std::stringstream ss;
		ss << "State " << static_cast<int>(state) << " does not exist";
		WRITE_LOG_WARNING(ss.str());
		break;
	}

	_FSM->changeState(newState);
}

GameObjectType GameObject::getType()
{
	return _type;
}

std::string GameObject::getTypeString()
{
	switch (getType())
	{
	case GameObjectType::Player:
		return "Player";
	case GameObjectType::Obstacle:
		return "Obstacle";
	case GameObjectType::Enemy:
		return "Enemy";
	case GameObjectType::Container:
		return "Container";
	default:
		return "<INVALID TYPE>";
	}
}

States GameObject::getState()
{
	return _FSM->getCurrentState();
}

std::string GameObject::getStateString()
{
	return _FSM->getCurrentStateString();
}

std::string GameObject::getInfo()
{
	return _stats->getInfo();
}

std::shared_ptr<GameObjectStats> GameObject::getStats()
{
	return _stats;
}

void GameObject::preMove(Directions direction)
{
}

void GameObject::move(Directions direction)
{
	preMove(direction);
	_gameLogicObjectInterface->moveObject(this, direction);
	postMove(direction);
}

void GameObject::postMove(Directions direction)
{
}

void GameObject::attack(GameObject* const gameObject, EquipSlot* const equipSlot)
{
	_gameLogicObjectInterface->attack(gameObject, equipSlot);
}

void GameObject::open(GameObject* const gameObject)
{
	_gameLogicObjectInterface->open(gameObject);
}

void GameObject::inspect(GameObject* const gameObject)
{
	_gameLogicObjectInterface->inspect(gameObject);
}

void GameObject::dead()
{
	_gameLogicObjectInterface->dead(this);
}

std::map<std::string, std::string> GameObject::serialize()
{
	std::map<std::string, std::string> serializedData;

	MyObjectDisplayData* displayData = dynamic_cast<MyObjectDisplayData*>(this);
	
	serializedData["Type"] = static_cast<int>(getType());
	serializedData["Texture"] = displayData->texturePath;
	serializedData["DimensionH"] = displayData->_dimension.h;
	serializedData["DimensionW"] = displayData->_dimension.w;
	serializedData["PositionX"] = displayData->_position.x;
	serializedData["PositionY"] = displayData->_position.y;
	serializedData["DrawLayer"] = static_cast<int>(displayData->_drawLayer);
	
	return serializedData;
}

void GameObject::deserialize(std::map<std::string, std::string>& data)
{
	MyObjectDisplayData* displayData = dynamic_cast<MyObjectDisplayData*>(this);

	_type = static_cast<GameObjectType>(std::stoi(data["Type"]));

	displayData->texturePath = data["Texture"];

	displayData->_dimension.h = std::stoi(data["DimensionH"]);
	displayData->_dimension.w = std::stoi(data["DimensionW"]);

	displayData->_position.x = std::stoi(data["PositionX"]);
	displayData->_position.y = std::stoi(data["PositionY"]);

	displayData->_drawLayer = static_cast<DrawingLayer>(std::stoi(data["DrawLayer"]));
}

void GameObject::equip(unsigned int inventorySlot, unsigned int equipSlot)
{
	
}
