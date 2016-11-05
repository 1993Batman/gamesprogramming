#include "stdafx.h"
#include "DamageComponent.h"


DamageComponent::DamageComponent(int dmg)
{
	_dmg = dmg;
}

string DamageComponent::GetDamage() const
{
	return to_string(_dmg) + " damage";
}

double DamageComponent::Attack( )
{
	double num = rand() % 1 + 10;
	if (num >= 8) {
		return round(1.5 * _dmg);
	}
	return _dmg;
}


DamageComponent::~DamageComponent()
{
}