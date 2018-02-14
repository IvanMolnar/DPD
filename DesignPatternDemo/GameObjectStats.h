#pragma once

#include "ObjectEventInterface.h"

#include <string>
#include <sstream>

using namespace std;

class GameObjectStats
{
public:
	GameObjectStats(ObjectEventInterface* eventInterface) : _eventInterface(eventInterface), _health(100), _stamina(100), _mana(100), _healthMax(100), _staminaMax(100), _manaMax(100) {};
	~GameObjectStats() {};

	string getInfo()
	{
		stringstream ss;

		ss << "Health " << _healthMax << "\\" << _health << "    Stamina " << _staminaMax << "\\" << _stamina << "    Mana " << _manaMax << "\\" << _mana << endl;

		return ss.str();
	}

	void regenerate()
	{
		_stamina += 20;

		if (_stamina > 100)
		{
			_stamina = 100;
		}
	}

	// returns true if dead
	bool addHealth(int value)
	{
		_health += value;

		if (_health < 1)
		{
			_eventInterface->changeState(States::dead);
			return true;
		}

		return false;
	}

	void addStamina(int value)
	{
		_stamina += value;
	}

	void addMana(int value)
	{
		_mana += value;
	}

	int getHealth()
	{
		return _health;
	}

	int getStamina()
	{
		return _stamina;
	}

	int getMana()
	{
		return _mana;
	}

private:
	int _health;
	int _stamina;
	int _mana;

	int _healthMax;
	int _staminaMax;
	int _manaMax;

	ObjectEventInterface* _eventInterface;
};

