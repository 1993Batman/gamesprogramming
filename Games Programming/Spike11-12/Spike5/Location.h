#pragma once
#include "Item.h"
#include "Edges.h"
#include <vector>
#include "Entity.h"
#include "DamageComponent.h"
#include "Message.h"

class Location
{
public:
	Location(string na, string de, vector<Edges*> ed,Entity e, Item i);
	~Location();
	string getName();
	string getDec();
	int getSize();
	vector<Edges*> getEdges();
	Entity getEntity();
	Item getItem();
	void setItem(Item* i);
	string getMessage(Message* m);
	DamageComponent returnDC();
	bool Location::getMessRes();
	void setMessRes(bool t);
	void GetDamage(int d);
private:
	string name;
	string desc;
	vector<Edges*> edges;
	Entity* entity;
	Item* item;
	DamageComponent* dc;
	bool messRes;
};