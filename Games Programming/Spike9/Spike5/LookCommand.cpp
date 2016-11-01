#include "stdafx.h"
#include "LookCommand.h"

LookCommand::LookCommand()
{
	lcVal.push_back(new string("look"));
	lcVal.push_back(new string("glance"));
	lcVal.push_back(new string("behold"));
	lcVal.push_back(new string("notice"));
	lcVal.push_back(new string("peer"));
	lcVal.push_back(new string("see"));
	lcVal.push_back(new string("stare"));
	lcVal.push_back(new string("study"));
	lcVal.push_back(new string("view"));
	lcVal.push_back(new string("gaze"));
}

LookCommand::~LookCommand()
{
	delete(&lcVal);
}


bool LookCommand::checkCommand(string m, Location* l) {
	vector<Edges*> e = vector<Edges*>(l->getEdges());
	vector<string> ss;
	
	Utilities::Split(m, ' ', ss);
	

	if (ss.size() == 2) {
		ss[1] = checkMovement(ss[1]);
		for (int i = 0; i < int(lcVal.size()); i++)
		{
			if (!lcVal.at(i)->compare(ss[0])) {
				for (int j = 0; j < int(e.size()); j++) {
					if (ss[1] == e.at(j)->getPath()) {
						cout << "You don't Zorkish well so want to see were the path leads" << endl;
						cout << "Path: " << e.at(j)->getDesc() << endl;
						if (l->getItem().ReturnName().compare("Null")) {
							cout << "But, I think there is an Item here at this location. It looks like a "<< l->getItem().ReturnName() <<endl;
						}
						if (l->getEntity().getName().compare("Null")) {
							cout << "But, I think there is an Entity at this location . It looks like the "<< l->getEntity().getName() << endl;
						}
						return true;
					}
				}
			}
		}
	}
	return false;
}

string LookCommand::checkMovement(string m) {
	if (m == "north" || m == "n") {
		return "north";
	}
	else if (m == "south" || m == "s") {
		return "south";
	}
	else if (m == "east" || m == "e") {
		return "east";
	}
	else if (m == "west" || m == "w") {
		return "west";
	}
	else if (m == "northwest" || m == "nw") {
		return "northwest";
	}
	else if (m == "northeast" || m == "ne") {
		return "northeast";
	}
	else if (m == "southwest" || m == "sw") {
		return "southwest";
	}
	else if (m == "southeast" || m == "se") {
		return "southeast";
	}
	return "No";
}
