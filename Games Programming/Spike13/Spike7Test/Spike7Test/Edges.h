#pragma once
#include "Header.h"
class Edges
{
public:
	Edges(string na, string no, string p, string d);
	~Edges();
	string getName();
	string getNode();
	string getDesc();
	string getPath();
private:
	string name;
	string node;
	string path;
	string desc;
};