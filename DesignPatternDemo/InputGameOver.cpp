#include "InputGameOver.h"

// example of keyboard input handling

InputGameOver::InputGameOver() : Input()
{/*
	Input::addText("  _____                         ____                 ", 0);
	Input::addText(" / ____|                       / __ \\                ", 0);
	Input::addText("| |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ ", 0);
	Input::addText("| | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|", 0);
	Input::addText("| |__| | (_| | | | | | |  __/ | |__| |\  V /  __/ |   ", 0);
	Input::addText(" \\_____|\__,_ |_| |_| |_|\___|   \\____/  \\_/ \\___|_|   ", 0);*/
	Input::addInputAction(inputAction(1, " ", Events::none, Directions::None, GameStates::MainMenu, 0, 0));
}

InputGameOver::~InputGameOver()
{
}
