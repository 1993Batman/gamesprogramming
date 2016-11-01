#include "stdafx.h"
#include "Item.h"

Item::Item()
{
}

Item::Item(string n, string t, string d) {
	name = new string(n);
	type = new string(t);
	desc = new string(d);
	dam = 0;
}

Item::~Item() {
	
}

string Item::ReturnName() {
	return *name;

}
string Item::ReturnType() {
	return *type;
}

string Item::ReturnDesc() {
	return *desc;
}

void Item::getDamage(int da)
{
	dam = &da;
	cout << dam << endl;
}

int Item::returnDamage()
{
	return *dam;
}
