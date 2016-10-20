#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(string n, string t, string d, int dam) {
	name = n;
	type = t;
	desc = d;
	damage = dam;
}

Weapon::~Weapon() {

}

string Weapon::returnName() {
	return name;
}
string Weapon::returnDesc() {
	return desc;
}
string Weapon::returnType() {
	return type;
}
int Weapon::returnDamage() {
	return damage;
}