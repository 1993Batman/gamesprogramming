#pragma once
class Item
{
public:
	Item();
	Item(string n, string t, string d);
	~Item();
	string ReturnName();
	string ReturnType();
	string ReturnDesc();
	void getDamage(int da);
	int returnDamage();
private:
	string* name;
	string* type;
	string* desc;
	int* dam;
};