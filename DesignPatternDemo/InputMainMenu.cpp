#include "InputMainMenu.h"

// example of keyboard input handling

InputMainMenu::InputMainMenu() : Input()
{/*
	Input::addText("    _/_/_/    _/_/_/    _/_/_/ ", 0);
	Input::addText("   _/    _/  _/    _/  _/    _/", 0);
	Input::addText("  _/    _/  _/_/_/    _/    _/ ", 0);
	Input::addText(" _/    _/  _/        _/    _/  ", 0);
	Input::addText("_/_/_/    _/        _/_/_/     ", 0);
	Input::addText("----------- Main menu ---------", 0);*/
	Input::addInputAction(inputAction('n', "New Game", Events::none, Directions::None, GameStates::NewGame, 0, 0));
	Input::addInputAction(inputAction('q', "Quit", Events::none, Directions::None, GameStates::ExitGame, 0, 0));
}

InputMainMenu::~InputMainMenu()
{
}