#pragma once

#include "Inventory.h"
class Player
{
public:
	Player();
	~Player();
	
private:
	Inventory inventory;
};