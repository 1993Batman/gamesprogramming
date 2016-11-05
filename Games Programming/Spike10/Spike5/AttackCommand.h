#pragma once
#include "Location.h"
class AttackCommand
{
public:
	AttackCommand();
	~AttackCommand();
	string checkCommand(string com, Location* l);
	bool checkAttack(string c);
private:
	vector<string*> acVal;
};

