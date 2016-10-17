// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

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

// TODO: reference additional headers your program requires here
