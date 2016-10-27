// Spike5.cpp : Defines the entry point for the console application.
//

#include "GameController.h"

int main()
{
	GameController* controller;
	controller = new GameController();

	controller->mainMenu();

	return 0;
}

