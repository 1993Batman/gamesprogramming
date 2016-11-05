#include "stdafx.h"
#include "Bag.h"

Bag::Bag()
{
	isOpen = false;
}


Bag::~Bag()
{
	delete(&bag);
}

void Bag::addToBag(Item i) {
	bag.insert(bag.begin(), i);
}
Item Bag::dropItem(Item i) {
	for (int j = 0; j < int(bag.size()); j++) {
		if (i.ReturnName() == bag.at(j).ReturnName()) {
			bag.erase(bag.begin() + j);
		}
	}
	return i;
}
void Bag::printItemsInBag() {
	if (int(bag.size()) > 0) {
		for (int i = 0; i < int(bag.size()); i++)
		{
			cout << "Item: " << bag.at(i).ReturnName() << endl;
			cout << "Type: " << bag.at(i).ReturnType() << endl;
			cout << "Desc: " << bag.at(i).ReturnDesc() << endl;
			cout << "Damage: " << bag.at(i).returnDC().GetDamage() << endl;
		}
	}
	else {
		cout << "Your bag is empty" << endl;
	}
}
void Bag::openCloseBag() {
	isOpen = !isOpen;
}

bool Bag::openCloseBagCheck() {
	return isOpen;
}

