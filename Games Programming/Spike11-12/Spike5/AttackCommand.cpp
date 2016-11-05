#include "stdafx.h"
#include "AttackCommand.h"


AttackCommand::AttackCommand()
{
	acVal = vector<string*>();
	acVal.push_back(new string("hit"));
	acVal.push_back(new string("attack"));
	acVal.push_back(new string("strike"));
	acVal.push_back(new string("slash"));
}


AttackCommand::~AttackCommand()
{
}

string AttackCommand::checkCommand(string com, Location* l)
{
	vector<string> ss;
	Utilities::Split(com, ' ', ss);
	if (int(ss.size()) >= 1) {
		if (checkAttack(ss[0])) {
			if (l->getEntity().getName() != "NULL") {
				if (ss[1] == "monster" || ss[1] == "entity") {
					
					return "attack entity";
				}

				if (ss[1] == "chicken" && ss[2] == "nugget" && ss[3] == "monster") {
					return "attack entity";
				}
			}
		}
	}
	return com;
}

bool AttackCommand::checkAttack(string c)
{
	for (int i = 0; i < int(acVal.size()); i++)
	{
		if (!acVal.at(i)->compare(c)) {
			return true;
		}
	}
	return false;
}
