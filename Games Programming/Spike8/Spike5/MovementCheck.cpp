#include "stdafx.h"
#include "MovementCheck.h"


MovementCheck::MovementCheck() {

}

MovementCheck::~MovementCheck() {

}

Location* MovementCheck::checkMovement(string m, Location* l, vector<Location*> ls) {
	vector<Edges*> posMove = l->getEdges();
	for (int i = 0; i < int(posMove.size()); i++) {
		for (int j = 0; j < int(l->getSize()); j++) {
			if (m == posMove.at(i)->getPath()) {
				if (posMove.at(i)->getNode() == ls.at(j)->getName()) {
					cout << posMove.at(i)->getDesc() << endl;
					return ls.at(j);
				}
			}
		}
	}
	return l;
}