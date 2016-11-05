#pragma once
#include "Item.h"
class ItemCommand
{
public:
	ItemCommand();
	~ItemCommand();
	string checkCommand(string com, vector<Item> ve, Item i);
	bool getAdd(string c);
	bool getRemove(string c);
private:
	vector<string*> acVal;
	vector<string*> rcVal;
};

