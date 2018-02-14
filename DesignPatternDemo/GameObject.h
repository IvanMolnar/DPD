#pragma once

#include <list>

using namespace std;

#include "FSM.h"
#include "ObjectEventInterface.h"
#include "ObjectCommandInterface.h"
#include "ObjectModifierInterface.h"
#include "ObjectModifier.h"

class GameObject : public ObjectEventInterface, public ObjectCommandInterface, public ObjectModifierInterface
{
public:
	GameObject(GameObjectTypes type);
	virtual ~GameObject();

	virtual void sendEvent(Events event, Directions direction, string& data, GameObject* object = nullptr);
	virtual void changeState(States state);
	GameObjectTypes getType();
	string getTypeString();
	States getState();
	string getStateString();
	virtual string getInfo();

	GameObjectStats* getStats();

	// modifiers like weapons, spells when attacked
	void acceptModifier(ObjectModifier& objectModifier);

	// modifiers like weapons, spells when attacking
	// returns if it's possible to attack
	bool acceptModifierSelf(ObjectModifier& objectModifier);

	list<EquipSlot*> getEquipSlots();
	list<ObjectModifier*> getInventoryItems();
	string getEquipItemsString();
	string getInventoryItemsString();
	void addItemToInventory(ObjectModifier* item);
	void removeItemFromInventory(ObjectModifier* item);
	array<float, 3> getModifiersPercent();

protected:
	FSM* _FSM;
	GameObjectTypes _type;
	GameObjectStats* _stats;
	list<ObjectModifier*> _inventoryItems;
	list<EquipSlot*> _equipSlots;

	virtual void move(Directions direction) = 0;
	virtual void inspect(GameObject* gameObject) = 0;
	virtual void attack(GameObject* gameObject);
	virtual void open(GameObject* gameObject);
	virtual void equip(unsigned int inventorySlot, unsigned int equipSlot);
	virtual void dead() = 0;
};

