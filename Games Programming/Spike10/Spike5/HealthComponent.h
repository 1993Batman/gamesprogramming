#pragma once
using namespace std;
class HealthComponent
{
private:
	double _maxHP;
	double _currHP;
public:
	HealthComponent(double currHP, double maxHP);

	double GetCurrentHealth();
	string GetHealth();
	void Damage(double dmg);
	~HealthComponent();

};