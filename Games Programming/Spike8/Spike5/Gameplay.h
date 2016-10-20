#pragma once
#include "Location.h"
#include "CommandManager.h"
class Gameplay
{
public:
	Gameplay();
	~Gameplay();
	void play();
	void printGameplay();
	void worldSetUp();
private:
	string move;
	vector<Location*> locations;
	Location* currLoc;
	CommandManager* cm;
};

