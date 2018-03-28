#pragma once

#include <list>

#include "FSM.h"
#include "ObjectEventInterface.h"
#include "ObjectCommandInterface.h"
#include "ObjectModifierInterface.h"
#include "ObjectModifier.h"
#include "MyObjectDisplayData.h"
#include "GameLogicObjectInterface.h"
#include "InventoryManager.h"

#include <memory>

class GameObject : public ObjectEventInterface, public ObjectCommandInterface, public ObjectModifierInterface, public MyObjectDisplayData, public std::enable_shared_from_this<GameObject>
{
public:
	GameObject(GameObjectType type);
	virtual ~GameObject();

	virtual void sendEvent(Events event, Directions direction, const std::string& data, std::shared_ptr<GameObject> object = nullptr) override;
	virtual void changeState(States state);
	GameObjectType getType();
	std::string getTypeString();
	States getState();
	std::string getStateString();
	virtual std::string getInfo();

	std::shared_ptr<GameObjectStats> getStats();

	std::list<EquipSlot*> getEquipSlots();
	std::list<ObjectModifier*> getInventoryItems();
	std::string getEquipItemsString();
	std::string getInventoryItemsString();
	void addItemToInventory(ObjectModifier* item);
	void removeItemFromInventory(ObjectModifier* item);
	std::array<float, 3> getModifiersPercent();

	

protected:
	std::unique_ptr<FSM> _FSM;
	GameObjectType _type;
	std::unique_ptr<InventoryManager> _inventoryManager;

	std::shared_ptr<GameObjectStats> _stats;

	// events
	virtual void preMove(Directions direction);
	virtual void postMove(Directions direction);

	virtual void move(Directions direction) override;
	virtual void inspect(std::shared_ptr<GameObject> gameObject) override;
	virtual void attack(std::shared_ptr<GameObject> gameObject, const std::shared_ptr<EquipSlot> equipSlot) override;
	virtual void open(std::shared_ptr<GameObject> gameObject) override;
	virtual void equip(unsigned int inventorySlot, unsigned int equipSlot) override;
	virtual void dead() override;

	GameLogicObjectInterface* _gameLogicObjectInterface;
};