#pragma once
#include "Gameplay.h"
class SelectAdventure
{
public:
	SelectAdventure();
	~SelectAdventure();
	void select();
	void printAdventure();
private:
	string move;
	Gameplay* gameplay;
};
