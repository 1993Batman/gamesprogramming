#pragma once
class Inventory
{
public:
	Inventory();
	Inventory(string name, string type, string desc);
	~Inventory();
	string ReturnName();
	string ReturnType();
	string ReturnDesc();
private:
	string* iName;
	string* iType;
	string* iDesc;
};