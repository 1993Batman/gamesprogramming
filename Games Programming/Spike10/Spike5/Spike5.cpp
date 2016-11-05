// Spike5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameController.h"

int main()
{
	//system("start https://youtu.be/XJZPW9aEEgk");
	GameController* controller;
	controller = new GameController();
	
	controller->mainMenu();

    return 0;
}

