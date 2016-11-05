#include "stdafx.h"
#include "HealthComponent.h"


HealthComponent::HealthComponent(double currHP, double maxHP)
{
	_maxHP = maxHP;
	_currHP = currHP;
}

double HealthComponent::GetCurrentHealth()
{
	return _currHP;
}

string HealthComponent::GetHealth()
{
	return "HP: " + to_string(_currHP) + "/" + to_string(_maxHP);
}

void HealthComponent::Damage(double  dmg)
{
	_currHP -= dmg;
	if (_currHP < 0)
	{
		_currHP = 0;
	}
}


HealthComponent::~HealthComponent()
{
}