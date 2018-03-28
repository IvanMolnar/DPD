#pragma once
#include "GameObject.h"
class Obstacle : public GameObject
{
public:
	Obstacle(GameLogicObjectInterface* gameLogicObjectInterface);
	~Obstacle();

	void sendEvent(Events event, Directions direction, const std::string& data, std::shared_ptr<GameObject> object = nullptr) override;

	void move(Directions direction) override;
	void inspect(std::shared_ptr<GameObject> gameObject) override;
	void attack(std::shared_ptr<GameObject> target, const std::shared_ptr<EquipSlot> equipSlot) override;

	// singnals death
	void dead();

	std::string getInfo();
};

