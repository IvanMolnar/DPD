#include "MainMenuScreen.h"


MainMenuScreen::MainMenuScreen() : Screen(screenType::mainMenu)
{
	Screen::addText("    _/_/_/    _/_/_/    _/_/_/ ", 0);
	Screen::addText("   _/    _/  _/    _/  _/    _/", 0);
	Screen::addText("  _/    _/  _/_/_/    _/    _/ ", 0);
	Screen::addText(" _/    _/  _/        _/    _/  ", 0);
	Screen::addText("_/_/_/    _/        _/_/_/     ", 0);
	Screen::addText("----------- Main menu ---------", 0);
	Screen::addInputAction(inputAction('n', "New Game", Events::none, Directions::None, GameStates::NewGame, 0, 0));
	Screen::addInputAction(inputAction('m', "New Game (alternative controls)", Events::none, Directions::None, GameStates::NewGameAlt, 0, 0));
	Screen::addInputAction(inputAction('q', "Quit", Events::none, Directions::None, GameStates::ExitGame, 0, 0));
}

MainMenuScreen::~MainMenuScreen()
{
}
