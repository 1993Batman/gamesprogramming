#pragma once
#include "Inventory.h"
#include "Edges.h"
#include <vector>

class Location
{
public:
	Location(string na, string de, vector<Edges> ed, bool ia);
	~Location();
	string getName();
	string getDec();
	Edges selectEdge(string n);
	bool getAmIAt();
	void setAmIAt(bool t);
	int getSize();
	vector<Edges> getEdges();
private:
	string name;
	string desc;
	vector<Edges>* edges;
	bool isAt;
};