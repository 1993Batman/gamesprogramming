#include "stdafx.h"
#include "Entity.h"

Entity::Entity(string n, string d, int h) {
	name = n;
	desc = d;
	health = h;
}

Entity::~Entity() {

}

string Entity::getName() {
	return name;
}

string Entity::getDesc() {
	return desc;
}

int Entity::getHealth() {
	return health;
}