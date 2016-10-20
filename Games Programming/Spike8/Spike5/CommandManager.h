#pragma once
#include "HighScore.h"
#include "LookCommand.h"
#include "MoveCommand.h"
#include "Location.h"
#include "Edges.h"
class CommandManager
{
public:
	CommandManager();
	~CommandManager();
	string checkCommand(string m, Location* l);
private:
	HighScore* hscore;
	LookCommand* lc;
	MoveCommand* mc;
};
