#pragma once
#include "Item.h"
#include <vector>
#include "Bag.h"
#include "HealthComponent.h"

class Player
{
public:
	Player();
	~Player();
	void AddItem(Item item);
	Item RemoveItem(Item item);
	Bag* getBag();
	void beenAttacked(double dam);
private:
	Bag* bag;
	HealthComponent* hc;
};