#include "stdafx.h"
#include "Help.h"

Help::Help()
{
}

Help::~Help()
{
}

void Help::printHelp() {
	string temp;
	cout << "Zorkish :: Help " << endl;
	cout << "----------------------------------------------" << endl;
	cout << " " << endl;
	cout << "These are the current commands supported" << endl;
	cout << "1. Quit" << endl;
	cout << "2. Highscore" << endl;
	cout << "" << endl;
	cout << " Press any key to continue" << endl;

	cin >> temp;
}