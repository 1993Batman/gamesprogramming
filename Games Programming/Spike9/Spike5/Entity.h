#pragma once
class Entity
{
public:
	Entity(string n, string d, int h);
	~Entity();
	string getName();
	string getDesc();
	int getHealth();
private:
	string name;
	string desc;
	int health;
};
