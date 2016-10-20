#pragma once
#include "Inventory.h"
class Weapon 
{
public:
	Weapon(string n, string t, string d, int dam);
	~Weapon();
	string returnName();
	string returnDesc();
	string returnType();
	int returnDamage();
private:
	string name;
	string desc;
	string type;
	int damage;
};