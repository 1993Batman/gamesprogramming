#pragma once


#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

namespace Utilities
{
	void Split(const string &s, char delim, vector<string> &elems);
};