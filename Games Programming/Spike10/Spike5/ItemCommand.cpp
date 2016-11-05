#include "stdafx.h"
#include "ItemCommand.h"


ItemCommand::ItemCommand()
{
	acVal = vector<string*>();
	acVal.push_back(new string ("add"));
	acVal.push_back(new string("put"));
	acVal.push_back(new string ("place"));
	acVal.push_back(new string ("pickup"));
	rcVal = vector<string*>();
	rcVal.push_back(new string("remove"));
	rcVal.push_back(new string("throw"));
	rcVal.push_back(new string("expel"));
}


ItemCommand::~ItemCommand()
{
	delete(&acVal);
	delete(&rcVal);
}

string ItemCommand::checkCommand(string com, vector<Item> ve, Item it)
{
	vector<string> ss;
	Utilities::Split(com, ' ', ss);
	if (int(ss.size()) >= 1 ) {

		if (getAdd(ss[0])) {
			if(int(ve.size()) > 0)
			for (int i = 0; i < int(ve.size()); i++) {
				if (!ve.at(i).ReturnName().compare(it.ReturnName()) && !it.ReturnName().compare(ss[1])) {
					return "add item";
				}
			}
			else if(!it.ReturnName().compare(ss[1])) {
				return "add item";
			}
			cout << "That item doesn't exist... so you add some dust top your bag instead" << endl;
			return " ";
		}

	}

	if (int(ss.size()) > 1) {

		if (getRemove(ss[0])) {
			for (int i = 0; i < int(ve.size()); i++) {
				if (!ve.at(i).ReturnName().compare(ss[1]) ) {
					return "remove " + ss[1];
				}
			}
			cout << "bag is emtpy... so you remove the dust at the bottom instead "<< endl;
			return " ";
		}

	}

	if (ss[0] == "look" && ss[1] == "in" && ss[2] == "bag") {
		if (int(ve.size()) > 0) {
			return "look in bag";
		}
	}
	return com;
}

bool ItemCommand::getAdd(string c)
{
	for (int i = 0; i < int(acVal.size()); i++)
	{
		if (!acVal.at(i)->compare(c)) {
			return true;
		}
	}
	return false;
}

bool ItemCommand::getRemove(string c)
{
	for (int i = 0; i < int(rcVal.size()); i++)
	{
		if (!rcVal.at(i)->compare(c)) {
			return true;
		}
	}
	return false;
}
