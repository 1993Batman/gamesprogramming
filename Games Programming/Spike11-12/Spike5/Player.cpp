#include "stdafx.h"
#include "Player.h"

Player::Player() {
	bag = new Bag();
	hc = new HealthComponent(10,10);
}

Player::~Player() {
	delete(bag);
}

void Player::AddItem(Item item) {
	bag->addToBag(item);
}

Item Player::RemoveItem(Item item) {
	bag->dropItem(item);
	return item;
}

Bag* Player::getBag() {
	return bag;
}


HealthComponent Player::returnHC() {
	return *hc;
}