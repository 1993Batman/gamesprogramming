#include "stdafx.h"
#include "Location.h"


Location::Location(string na, string de, vector<Edges*> ed, Entity e, Item i) {
	name = na;
	desc = de;
	edges = vector<Edges*>(ed);
	entity = new Entity(e);
	item = new Item(i);

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