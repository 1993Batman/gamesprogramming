#pragma once
#include "Location.h"
class LookCommand
{
public:
	LookCommand();
	~LookCommand();
	bool checkCommand(string com, Location* l);
	string checkMovement(string m);
private:
	vector<string*> lcVal;

};
