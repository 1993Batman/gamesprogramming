#include "stdafx.h"
#include "About.h"

About::About()
{
}

About::~About()
{
}
void About::printAbout() {
	char temp;
	cout << "Zorkish :: About" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " " << endl;
	cout << "Written by Steven Efthimiadis" << endl;
	cout << " " << endl;
	cout << "Press any key to return to the Main Menu" << endl;
	cin >> temp;
}