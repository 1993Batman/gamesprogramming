#pragma once
#include "HealthComponent.h"
#include "DamageComponent.h"
class Entity
{
public:
	Entity(string n, string d);
	~Entity();
	string getName();
	string getDesc();
	void beenAttacked(double dam);
	void printInfo();
private:
	string name;
	string desc;
	HealthComponent* hc;
};
