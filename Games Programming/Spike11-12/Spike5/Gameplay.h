#pragma once
#include "Location.h"
#include "CommandManager.h"
#include "Entity.h"
#include "Item.h"
#include "Player.h"
#include "MessageHandler.h"
#include "Message.h"

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
	int currLoc;
	CommandManager* cm;
	Player* player;
	MessageHandler* bb;
};

