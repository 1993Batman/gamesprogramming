#include "stdafx.h"
#include "SelectAdventure.h"


SelectAdventure::SelectAdventure()
{
	move = " ";
	gameplay = new Gameplay();
}

SelectAdventure::~SelectAdventure()
{
	delete(gameplay);
}

void SelectAdventure::select() {
	bool inPlay = true;
	
	while (inPlay) {
		printAdventure();
		switch (move[0]) {
		case '1':
			gameplay->play();
			inPlay = false;
			break;
		case '2':
			gameplay->play();
			inPlay = false;
			break;
		case '3':
			gameplay->play();
			inPlay = false;
			break;
		default:
			if (move == "1" || move == "2" || move == "3") {

			}
			else {
				cout << "invalid move" << endl;
			}
			break;
		}
	}


}

void SelectAdventure::printAdventure() {
	cout << "Zorkish :: Select Adventure" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " " << endl;
	cout << "1. Mountatin World" << endl;
	cout << "2. Water World" << endl;
	cout << "3. Box World" << endl;
	cout << " " << endl;
	cout << "Select 1-3" << endl;
	cin >> move;
}