#pragma once
#include "HighScore.h"
#include "LookCommand.h"
#include "MoveCommand.h"
#include "OpenCloseCommand.h"
#include "ItemCommand.h"
#include "Location.h"
#include "Edges.h"
#include "AttackCommand.h"
class CommandManager
{
public:
	CommandManager();
	~CommandManager();
	string checkCommand(string m, Location* l, vector<Item> ve);
private:
	HighScore* hscore;
	LookCommand* lc;
	MoveCommand* mc;
	OpenCloseCommand* occ;
	ItemCommand* ic;
	AttackCommand*ac;
};
