#pragma once
class DamageComponent
{
private:
	int _dmg;
public:
	DamageComponent(int dmg);
	string GetDamage() const;
	double Attack ();
	~DamageComponent();
};