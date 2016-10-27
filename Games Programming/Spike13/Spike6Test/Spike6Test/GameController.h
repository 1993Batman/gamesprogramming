#pragma once
#include "Player.h"
#include "Inventory.h"

class GameController
{
public:
	GameController();
	~GameController();
	void mainMenu();
	void printMenu();
	void testInventory();
private:
	string move;
	Player* player;
};


