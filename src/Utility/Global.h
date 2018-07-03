#pragma once

#include "Log\Log.h"

enum class States
{
	standingUp,
	sneaking,
	dead
};

enum class Events
{
	none,
	walk,
	inspect,
	attack,
	interact,
	equip,
	sneak,
	standUp
};

enum class Directions
{
	None,
	North,
	South,
	West,
	East
};

enum class GameObjectType
{
	Player,
	Obstacle,
	Enemy,
	Container,
	Door,
	Tile
};

enum class GameStates
{
	Unchanged,
	MainMenu,
	NewGame,
	Loading,
	GameRunning,
	GameOver,
	ExitGame
};