#pragma once
#include "Inventory.h"
#include <list>
#include <vector>

class Player
{
public:
	Player();
	~Player();
	void AddItem(Inventory item);
	void RemoveItem(Inventory item);
	void ShowItems();
private:
	vector <Inventory>* inventory;
};