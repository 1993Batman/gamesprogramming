#include "stdafx.h"
#include "Player.h"

Player::Player() {
	inventory = new  vector<Inventory>();
}

Player::~Player() {
	delete(inventory);
}

void Player::AddItem(Inventory item) {
	auto it = inventory->begin();
	inventory->insert(it, item);
}

void Player::RemoveItem(Inventory item) {
	auto it = inventory->begin();
	

	for (int i = 0; i < int(inventory->size()); i++) {
		string test = inventory->at(i).ReturnName;
		if (!test.compare(item.ReturnName)) {
			inventory->erase((it +i));
		}
	}
	
}

void Player::ShowItems() {
	for (int i = 0; i < int(inventory->size()); i++) {
		cout << "1. " << inventory->at(i).ReturnName << " : " << inventory->at(i).ReturnType << endl;
		cout << inventory->at(i).ReturnDesc << endl;
	}
}