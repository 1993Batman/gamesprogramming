#pragma once
#include "Item.h"
#include <vector>
#include "Bag.h"

class Player
{
public:
	Player();
	~Player();
	void AddItem(Item item);
	Item RemoveItem(Item item);
	Bag* getBag();
private:
	Bag* bag;
};