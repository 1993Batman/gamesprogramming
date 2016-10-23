// stdafx.cpp : source file that includes just the standard includes
// Spike5.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

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
