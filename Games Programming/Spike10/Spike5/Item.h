#pragma once
#include "DamageComponent.h"
class Item
{
public:
	Item(string n, string t, string d);
	~Item();
	string ReturnName();
	string ReturnType();
	string ReturnDesc();
	void GetDamage(int dc);
	double returnDamage();

	DamageComponent returnDC();

private:
	string* name;
	string* type;
	string* desc;
	DamageComponent* dc;
};