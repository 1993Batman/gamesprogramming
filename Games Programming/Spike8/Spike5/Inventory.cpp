#include "stdafx.h"
#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::Inventory(string name, string type, string desc) {
	iName = new string(name);
	iType = new string(type);
	iDesc = new string(desc);
}

Inventory::~Inventory() {

}

string Inventory::ReturnName() {
	return *iName;

}
string Inventory::ReturnType() {
	return *iType;
}

string Inventory::ReturnDesc() {
	return *iDesc;
}