#pragma once
class MoveCommand
{
public:
	MoveCommand();
	~MoveCommand();
	string checkCommand(string com);
private:
	vector<string*> mcVal;

};
