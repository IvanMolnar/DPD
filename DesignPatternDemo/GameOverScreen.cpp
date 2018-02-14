#include "GameOverScreen.h"

GameOverScreen::GameOverScreen() : Screen(screenType::gameOver)
{
	Screen::addText("  _____                         ____                 ", 0);
	Screen::addText(" / ____|                       / __ \\                ", 0);
	Screen::addText("| |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ ", 0);
	Screen::addText("| | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|", 0);
	Screen::addText("| |__| | (_| | | | | | |  __/ | |__| |\  V /  __/ |   ", 0);
	Screen::addText(" \\_____|\__,_ |_| |_| |_|\___|   \\____/  \\_/ \\___|_|   ", 0);
	Screen::addPresEnter(GameStates::MainMenu);
}

GameOverScreen::~GameOverScreen()
{
}
