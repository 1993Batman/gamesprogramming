#include "stdafx.h"
#include "MoveCommand.h"

MoveCommand::MoveCommand()
{
	mcVal = vector<string*>();
	mcVal.push_back(new string("move"));
	mcVal.push_back(new string("advance"));
	mcVal.push_back(new string("relocate"));
	mcVal.push_back(new string("cross"));
	mcVal.push_back(new string("go"));
	mcVal.push_back(new string("run"));
	mcVal.push_back(new string("walk"));
	mcVal.push_back(new string("proceed"));
	mcVal.push_back(new string("progress"));
	mcVal.push_back(new string("crawl"));
}

MoveCommand::~MoveCommand()
{
	delete(&mcVal);
}

string MoveCommand::checkCommand(string com) {
	vector<string> ss;
	Utilities::Split(com, ' ', ss);
	if (int(ss.size()) == 2) {
		for (int i = 0; i < int(mcVal.size()); i++)
		{
			if (mcVal.at(i)->compare(ss[0])) {
				com = ss[1];
				break;
			}
		}
	}


	if (com == "north" || com == "n") {
		return "north";
	}
	else if (com == "south" || com == "s") {
		return "south";
	}
	else if (com == "east" || com == "e") {
		return "east";
	}
	else if (com == "west" || com == "w") {
		return "west";
	}
	else if (com == "northwest" || com == "nw") {
		return "northwest";
	}
	else if (com == "northeast" || com == "ne") {
		return "northeast";
	}
	else if (com == "southwest" || com == "sw") {
		return "southwest";
	}
	else if (com == "southeast" || com == "se") {
		return "southeast";
	}
	return "No";
}