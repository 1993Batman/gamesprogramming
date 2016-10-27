
#include "Edges.h"

Edges::Edges(string na, string no, string p, string d) {
	name = na;
	node = no;
	path = p;
	desc = d;
}

Edges::~Edges() {}

string Edges::getName() {
	return name;
}
string Edges::getNode() {
	return node;
}
string Edges::getPath() {
	return path;
}
string Edges::getDesc() {
	return desc;
}