#include "Header.h"

void Utilities::Split(const string &s, char delim, vector<string>& elems)
{
	// Credit:
	// http://stackoverflow.com/questions/236129/split-a-string-in-c

	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}
