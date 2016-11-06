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
	HealthComponent returnHC();
private:
	Bag* bag;
	HealthComponent* hc;
};