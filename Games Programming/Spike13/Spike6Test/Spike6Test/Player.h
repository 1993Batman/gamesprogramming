#pragma once
#include "Inventory.h"

class Player
{
public:
	Player();
	~Player();
	void AddItem(Inventory* item);
	void RemoveItem(Inventory* item);
	void ShowItems();
	vector <Inventory*> inventory;
private:

};