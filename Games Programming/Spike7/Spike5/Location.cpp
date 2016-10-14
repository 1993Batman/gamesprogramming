#include "stdafx.h"
#include "Location.h"


Location::Location(string na, string de, vector<Edges> ed, bool ia) {
	name = na;
	desc = de;
	edges = new vector<Edges>();
	for (int i = 0; i < int(ed.size()); i++) {
		auto it = edges->begin();
		edges->insert(it,ed[i]);
	}
	isAt = ia;
}

Location::~Location() {
	delete(edges);

}

string Location::getName() {
	return name;
}

string Location::getDec() {
	return desc;
}

Edges Location::selectEdge(string n) {
	for (int i = 0; i < int(edges->size()); i++) {
		string test = edges->at(i).getName();
		if (!test.compare(edges->at(i).getName())) {
			return edges->at(i);
		}
	}
	return edges->at(0);
}

bool Location::getAmIAt() {
	return isAt;
}

void Location::setAmIAt(bool t) {
	isAt = t;
}

int Location::getSize() {
	return edges->size();
}

vector<Edges> Location::getEdges() {
	return *edges;
}