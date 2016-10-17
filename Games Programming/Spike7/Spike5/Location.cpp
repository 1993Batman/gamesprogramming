#include "stdafx.h"
#include "Location.h"


Location::Location(string na, string de, vector<Edges> ed) {
	name = na;
	desc = de;
	edges = new vector<Edges>();
	for (int i = 0; i < int(ed.size()); i++) {
		auto it = edges->begin();
		edges->insert(it,ed[i]);
	}
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


int Location::getSize() {
	return edges->size();
}

vector<Edges> Location::getEdges() {
	return *edges;
}