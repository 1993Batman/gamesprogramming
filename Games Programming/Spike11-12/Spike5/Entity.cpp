#include "stdafx.h"
#include "Entity.h"

Entity::Entity(string n, string d) {
	name = n;
	desc = d;
	hc = new HealthComponent(10,10);
}

Entity::~Entity() {

}

string Entity::getName() {
	return name;
}

string Entity::getDesc() {
	return desc;
}



void Entity::beenAttacked(double dam) {
	if (hc->GetCurrentHealth() > 0) {
		hc->Damage(dam);
	}
	else {
		cout << "Stop it! The Chicken Nugget Monster is already DEAD" << endl;
	}
}

void Entity::printInfo() {
	cout << name << endl;
	cout << hc->GetCurrentHealth()<< endl;
}