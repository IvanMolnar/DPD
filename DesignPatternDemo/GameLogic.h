#pragma once

#include "MapManager.h"
#include "Input.h"
#include "Display.h"
#include "MapAreaInterface.h"
#include "GameObjectFactory.h"
#include <memory>
#include <map>

class GameLogic : public GameLogicObjectInterface, public MapAreaInterface
{
public:
	GameLogic();
	virtual ~GameLogic();

	void init(std::unique_ptr<Display>& display, std::unique_ptr<MapManager>& mapManager);

	void run();

protected:
	std::shared_ptr<Input> _currentInput;
	std::unique_ptr<Display> _display;
	std::unique_ptr<MapManager> _mapManager;
	GameStates _currentState;
	bool _gameRunning;
	void startGame();
	void loadLevel(const std::string& levelPath);
	void processInput();
	void moveObject(std::shared_ptr<GameObject> gameObject, Directions direction);
	void internalProcessState(GameStates gameEvent);
	
	virtual void processAction(const resultAction& action) = 0;
	virtual bool processState(GameStates gameEvent) = 0;
	virtual void setInput(const std::shared_ptr<Input> newInput) = 0;
	virtual std::unique_ptr<Display> createDisplay() = 0;
	virtual std::unique_ptr<MapManager> createMapManager() = 0;


	// requests from GameObject
	void inspect(const GameObject * const gameObject) override;
	void attack(const GameObject * const gameObject, const EquipSlot * const equipSlot) override;
	void open(const GameObject * const gameObject) override;
	void dead(const GameObject * const gameObject) override;
	void enterDoor(const GameObject * const gameObject) override;


	std::string getDisplayData();
};