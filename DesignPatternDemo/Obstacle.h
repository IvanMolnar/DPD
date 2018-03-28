#pragma once
#include "GameObject.h"
class Obstacle : public GameObject
{
public:
	Obstacle(GameLogicObjectInterface* gameLogicObjectInterface);
	~Obstacle();

	void sendEvent(Events event, Directions direction, const std::string& data, const GameObject * const object = nullptr) override;

	void move(Directions direction) override;
	void inspect(const GameObject * const gameObject) override;
	void attack(const GameObject * const target, const EquipSlot * const equipSlot) override;

	// singnals death
	void dead();

	std::string getInfo();
};

