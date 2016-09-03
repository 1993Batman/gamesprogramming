#pragma once
#include "HighScore.h"
class Gameplay
{
public:
	Gameplay();
	~Gameplay();
	void play();
	void printGameplay();
private:
	string move;
	HighScore* hscore;
};

