#pragma once

#include <list>

#include "FSM\FSM.h"
#include "Interfaces\ObjectEventInterface.h"
#include "Interfaces\ObjectCommandInterface.h"
#include "Interfaces\ObjectModifierInterface.h"
#include "Items\ObjectModifier.h"
#include "MyObjectDisplayData.h"
#include "Interfaces\GameLogicObjectInterface.h"
#include "Items\InventoryManager.h"
#include "Serializer.h"

#include <memory>

class GameObject : public ObjectEventInterface, public ObjectCommandInterface, public ObjectModifierInterface, public MyObjectDisplayData, public Serializer
{
public:
	GameObject(GameLogicObjectInterface* gameLogicObjectInterface, GameObjectType type);
	virtual ~GameObject();

	virtual void sendEvent(Events event, Directions direction, const std::string& data, GameObject* const object = nullptr) override;
	virtual void changeState(States state);
	GameObjectType getType();
	std::string getTypeString();
	States getState();
	std::string getStateString();
	virtual std::string getInfo();

	std::shared_ptr<GameObjectStats> getStats();


	std::map<std::string, std::string> serialize() override;
	void deserialize(std::map<std::string, std::string>& data) override;

protected:
	std::unique_ptr<FSM> _FSM;
	GameObjectType _type;
	std::unique_ptr<InventoryManager> _inventoryManager;

	std::shared_ptr<GameObjectStats> _stats;

	// events
	virtual void preMove(Directions direction);
	virtual void postMove(Directions direction);

	virtual void move(Directions direction) override;
	virtual void inspect(GameObject* const gameObject) override;
	virtual void attack(GameObject* const gameObject, EquipSlot* const equipSlot) override;
	virtual void open(GameObject* const gameObject) override;
	virtual void equip(unsigned int inventorySlot, unsigned int equipSlot) override;
	virtual void dead() override;
	

	GameLogicObjectInterface* _gameLogicObjectInterface;
};