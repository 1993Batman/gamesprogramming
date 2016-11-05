#include "stdafx.h"
#include "Item.h"


Item::Item(string n, string t, string d) {
	name = new string(n);
	type = new string(t);
	desc = new string(d);
	dc = new DamageComponent(0);
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

void Item::GetDamage(int d)
{ 
	delete dc;
	dc = new DamageComponent(d);
}

double Item::returnDamage()
{
	return dc->Attack();
}
DamageComponent Item::returnDC()
{
	return *dc;
}