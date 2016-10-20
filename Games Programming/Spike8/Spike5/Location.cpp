#include "stdafx.h"
#include "Location.h"


Location::Location(string na, string de, vector<Edges*> ed, Entity e, Inventory i, Weapon w) {
	name = na;
	desc = de;
	edges = vector<Edges*>(ed);
	entity = new Entity(e);
	item = new Inventory(i);
	wep = new Weapon(w);
}

Location::~Location() {
	delete(&edges);
	delete(entity);
	delete(item);
	delete(wep);

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
Inventory Location::getInventory() {
	return *item;
}
Weapon Location::getWeapon() {
	return *wep;
}