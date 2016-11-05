#pragma once
#include "About.h"
#include "Help.h"
#include "HighScore.h"
#include "SelectAdventure.h"

class GameController
{
public:
	GameController();
	~GameController();
	void mainMenu();
	void printMenu();
private:
	string move;
	About* about;
	Help* help;
	HighScore* highScore;
	SelectAdventure* adventure;
};


