#pragma once
#include "HighScore.h"
#include "Location.h"
#include "Header.h"
class Gameplay
{
public:
	Gameplay();
	~Gameplay();
	void play();
	void printGameplay();
	void setUpLocations();
	void worldSetUp();
	vector<Location*> locations;
	Location* currLoc;
private:
	string move;
	HighScore* hscore;
};

