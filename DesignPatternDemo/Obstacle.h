#pragma once
#include "GameObject.h"
class Obstacle : public GameObject
{
public:
	Obstacle(GameLogicObjectInterface* gameLogicObjectInterface);
	~Obstacle();

	void sendEvent(Events event, Directions direction, const std::string& data, GameObject* const object = nullptr) override;

	void move(Directions direction) override;
	void inspect(GameObject* const gameObject) override;
	void attack(GameObject* const target, EquipSlot* const equipSlot) override;

	// singnals death
	void dead();

	std::string getInfo();
};

