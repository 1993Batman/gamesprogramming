#pragma once
#include "HighScore.h"
#include "Location.h"
class Gameplay
{
public:
	Gameplay();
	~Gameplay();
	void play();
	void printGameplay();
	void setUpLocations();
	void worldSetUp();
private:
	string move;
	HighScore* hscore;
	vector<Location*> *locations;
	Location* currLoc;
};

