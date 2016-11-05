#pragma once
#pragma once
#include "Item.h"
class Bag
{
public:
	Bag();
	~Bag();
	void addToBag(Item i);
	Item dropItem(Item i);
	void printItemsInBag();
	void openCloseBag();
	bool openCloseBagCheck();
	vector<Item> bag;
private:
	
	bool isOpen;
};

