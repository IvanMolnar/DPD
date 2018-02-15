#include "InputCommandAlt.h"

// example of keyboard input handling

InputCommandAlt::InputCommandAlt() : Input(screenType::gameCommand)
{
//	Input::addText("----------- Select option -----------", 0);
	Input::addInputAction(inputAction('`', "Main Menu", Events::none, Directions::None, GameStates::MainMenu, 0, 0));
	Input::addInputAction(inputAction('w', "Walk North", Events::walk, Directions::North, GameStates::Unchanged, 0, 0));
	Input::addInputAction(inputAction('s', "Walk South", Events::walk, Directions::South, GameStates::Unchanged, 0, 0));
	Input::addInputAction(inputAction('a', "Walk West", Events::walk, Directions::West, GameStates::Unchanged, 0, 0));
	Input::addInputAction(inputAction('d', "Walk East", Events::walk, Directions::East, GameStates::Unchanged, 0, 0));
	Input::addInputAction(inputAction('c', "Actions", Events::none, Directions::None, GameStates::Unchanged, 3, 0));
	Input::addInputAction(inputAction('q', "Equip", Events::equip, Directions::None, GameStates::Unchanged, 0, 0, true));
	Input::addInputAction(inputAction('r', "Change State", Events::none, Directions::None, GameStates::Unchanged, 2, 0));

//	Input::addText("----------- Select action -----------", 1);
	Input::addInputAction(inputAction('r', "Inspect", Events::inspect, Directions::None, GameStates::Unchanged, 0, 1));
	Input::addInputAction(inputAction('t', "Attack", Events::attack, Directions::None, GameStates::Unchanged, 0, 1));
	Input::addInputAction(inputAction('f', "Interact", Events::interact, Directions::None, GameStates::Unchanged, 0, 1));

//  Input::addText("----------- Change State -----------", 2);
	Input::addInputAction(inputAction('s', "Sneak", Events::sneak, Directions::None, GameStates::Unchanged, 0, 2));
	Input::addInputAction(inputAction('w', "Stand Up", Events::standUp, Directions::None, GameStates::Unchanged, 0, 2));

//	Input::addText("----------- Select Direction -----------", 3);
	Input::addInputAction(inputAction('w', "North", Events::none, Directions::North, GameStates::Unchanged, 1, 3));
	Input::addInputAction(inputAction('s', "South", Events::none, Directions::South, GameStates::Unchanged, 1, 3));
	Input::addInputAction(inputAction('a', "West", Events::none, Directions::West, GameStates::Unchanged, 1, 3));
	Input::addInputAction(inputAction('d', "East", Events::none, Directions::East, GameStates::Unchanged, 1, 3));
}

InputCommandAlt::~InputCommandAlt()
{
}
