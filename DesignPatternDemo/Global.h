#pragma once

#include "ConsoleLogger.h"

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
	Door
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

struct position2d
{
	position2d(int xPos = 0, int yPos = 0)
	{
		x = xPos;
		y = yPos;
	}

	int x;
	int y;
};


class Logger
{
public:
	static CConsoleLoggerEx& getInstance()
	{
		static CConsoleLoggerEx instance;
		return instance;
	}

	static void createLogWindow(char* name)
	{
		getInstance().Create(name);
	}

	static void closeLogWindow()
	{
		getInstance().Close();
	}

private:
	Logger() {}
	Logger(const Logger &old);
	const Logger &operator=(const Logger &old);
	~Logger() {}
};

#define CREATE_LOG_WINDOW(name) Logger::createLogWindow(name);
#define CLOSE_LOG_WINDOW Logger::closeLogWindow();
#define WRITE_LOG(log) Logger::getInstance().SetCurrentColor(CConsoleLoggerEx::enumColors::COLOR_WHITE); Logger::getInstance().printLine(log);
#define WRITE_LOG_WARNING(log) Logger::getInstance().SetCurrentColor(CConsoleLoggerEx::enumColors::COLOR_YELLOW); Logger::getInstance().printLine(log);
#define WRITE_LOG_GAME(log) Logger::getInstance().SetCurrentColor(CConsoleLoggerEx::enumColors::COLOR_GREEN); Logger::getInstance().printLine(log);