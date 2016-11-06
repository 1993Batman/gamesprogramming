#include "stdafx.h"
#include "Location.h"


Location::Location(string na, string de, vector<Edges*> ed, Entity e, Item i) {
	name = na;
	desc = de;
	edges = vector<Edges*>(ed);
	entity = new Entity(e);
	item = new Item(i);
	dc = nullptr;
	messRes = false;
}

Location::~Location() {
	delete(&edges);
	delete(entity);
	delete(item);


}

string Location::getName() {
	return name;
}

string Location::getDec() {
	return desc;
}


int Location::getSize() {
	return edges.size();
}

vector<Edges*> Location::getEdges() {
	return edges;
}

Entity Location::getEntity() {
	return *entity;
}
Item Location::getItem() {
	return *item;
}
void Location::setItem(Item* i) {
	item = i;
}

string Location::getMessage(Message * m)
{
	if (m->getAction() == Attack) {
		messRes = true;
		return " ";
	}
	else if (m->getAction() == Move) {
		return "move " + m->getTarget();
	} 
	else {
		cout << "Unknown Message" << endl;
		return " ";
	}
	 
}

DamageComponent Location::returnDC() {
	return *dc;
}
bool Location::getMessRes() {
	return messRes;
}

void Location::setMessRes(bool t) {
	messRes = t;
}
void Location::GetDamage(int d)
{
	delete dc;
	dc = new DamageComponent(d);
}
