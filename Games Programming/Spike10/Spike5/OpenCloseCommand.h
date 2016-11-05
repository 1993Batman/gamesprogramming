#pragma once
class OpenCloseCommand
{
public:
	OpenCloseCommand();
	~OpenCloseCommand();
	string checkCommand(string com);
	bool getOpen(string c);
	bool getClose(string c);
private:
	vector<string*> ocVal;
	vector<string*> ccVal;
};

