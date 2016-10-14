// Spike5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameController.h"

int main()
{
	GameController* controller;
	controller = new GameController();
	
	controller->mainMenu();

    return 0;
}

