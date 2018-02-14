#include "GameCommandScreenAlt.h"

GameCommandScreenAlt::GameCommandScreenAlt() : Screen(screenType::gameCommand)
{
	Screen::addText("----------- Select option -----------", 0);
	Screen::addInputAction(inputAction('`', "Main Menu", Events::none, Directions::None, GameStates::MainMenu, 0, 0));
	Screen::addInputAction(inputAction('w', "Walk North", Events::walk, Directions::North, GameStates::Unchanged, 0, 0));
	Screen::addInputAction(inputAction('s', "Walk South", Events::walk, Directions::South, GameStates::Unchanged, 0, 0));
	Screen::addInputAction(inputAction('a', "Walk West", Events::walk, Directions::West, GameStates::Unchanged, 0, 0));
	Screen::addInputAction(inputAction('d', "Walk East", Events::walk, Directions::East, GameStates::Unchanged, 0, 0));
	Screen::addInputAction(inputAction('c', "Actions", Events::none, Directions::None, GameStates::Unchanged, 3, 0));
	Screen::addInputAction(inputAction('q', "Equip", Events::equip, Directions::None, GameStates::Unchanged, 0, 0, true));
	Screen::addInputAction(inputAction('r', "Change State", Events::none, Directions::None, GameStates::Unchanged, 2, 0));

	Screen::addText("----------- Select action -----------", 1);
	Screen::addInputAction(inputAction('r', "Inspect", Events::inspect, Directions::None, GameStates::Unchanged, 0, 1));
	Screen::addInputAction(inputAction('t', "Attack", Events::attack, Directions::None, GameStates::Unchanged, 0, 1));
	Screen::addInputAction(inputAction('f', "Interact", Events::interact, Directions::None, GameStates::Unchanged, 0, 1));

	Screen::addText("----------- Change State -----------", 2);
	Screen::addInputAction(inputAction('s', "Sneak", Events::sneak, Directions::None, GameStates::Unchanged, 0, 2));
	Screen::addInputAction(inputAction('w', "Stand Up", Events::standUp, Directions::None, GameStates::Unchanged, 0, 2));

	Screen::addText("----------- Select Direction -----------", 3);
	Screen::addInputAction(inputAction('w', "North", Events::none, Directions::North, GameStates::Unchanged, 1, 3));
	Screen::addInputAction(inputAction('s', "South", Events::none, Directions::South, GameStates::Unchanged, 1, 3));
	Screen::addInputAction(inputAction('a', "West", Events::none, Directions::West, GameStates::Unchanged, 1, 3));
	Screen::addInputAction(inputAction('d', "East", Events::none, Directions::East, GameStates::Unchanged, 1, 3));
}

GameCommandScreenAlt::~GameCommandScreenAlt()
{
}
