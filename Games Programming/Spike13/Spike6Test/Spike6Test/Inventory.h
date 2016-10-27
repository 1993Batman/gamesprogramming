#pragma once
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Inventory
{
public:
	Inventory(string name, string type, string desc);
	~Inventory();
	string ReturnName();
	string ReturnType();
	string ReturnDesc();
private:
	string* iName;
	string* iType;
	string* iDesc;
};