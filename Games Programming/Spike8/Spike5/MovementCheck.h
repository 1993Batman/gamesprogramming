#pragma once
#include "Location.h"
#include "Edges.h"
class MovementCheck
{
public:
	MovementCheck();
	~MovementCheck();
	Location* checkMovement(string m, Location* l, vector<Location*> ls);
private:
};
