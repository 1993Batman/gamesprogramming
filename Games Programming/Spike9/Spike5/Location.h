#pragma once
#include "Inventory.h"
#include "Edges.h"
#include <vector>
#include "Entity.h"
#include "Weapon.h"

class Location
{
public:
	Location(string na, string de, vector<Edges*> ed,Entity e, Inventory i, Weapon w);
	~Location();
	string getName();
	string getDec();
	int getSize();
	vector<Edges*> getEdges();
	Entity getEntity();
	Inventory getInventory();
	Weapon getWeapon();
private:
	string name;
	string desc;
	vector<Edges*> edges;
	Entity* entity;
	Inventory* item;
	Weapon* wep;
};