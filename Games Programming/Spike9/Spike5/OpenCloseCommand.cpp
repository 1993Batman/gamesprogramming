#include "stdafx.h"
#include "OpenCloseCommand.h"


OpenCloseCommand::OpenCloseCommand()
{
	ccVal = vector<string*>();
	ccVal.push_back(new string("close"));
	ccVal.push_back(new string("shut"));
	ccVal.push_back(new string("lock"));
	ccVal.push_back(new string("seal"));
	ocVal = vector<string*>();
	ocVal.push_back(new string("open"));
	ocVal.push_back(new string("unlock"));
	ocVal.push_back(new string("free"));
	ocVal.push_back(new string("release"));
}


OpenCloseCommand::~OpenCloseCommand()
{
	delete(&ccVal);
	delete(&ocVal);
}

string OpenCloseCommand::checkCommand(string com)
{
	vector<string> ss;
	Utilities::Split(com, ' ', ss);
	if (int(ss.size()) == 2 && ss[1] == "bag") {

		if (getOpen(ss[0])) {
			return "open bag";
		}
		if (getClose(ss[0])) {
			return "close bag";
		}
	}


	return com;
}

bool OpenCloseCommand::getOpen(string c) {
	for (int i = 0; i < int(ocVal.size()); i++)
	{
		if (!ocVal.at(i)->compare(c)) {
			return true;
		}
	}
	return false;
}

bool OpenCloseCommand::getClose(string c) {
	for (int i = 0; i < int(ccVal.size()); i++)
	{
		if (!ccVal.at(i)->compare(c)) {
			return true;
		}
	}
	return false;
}