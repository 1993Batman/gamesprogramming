#include "stdafx.h"
#include "GameController.h"

GameController::GameController() {
	move = " ";
	about = new About();
	help = new Help();
	highScore = new HighScore();
	adventure = new SelectAdventure();
}

GameController::~GameController()
{
	delete(about);
	delete(help);
	delete(highScore);
	delete(adventure);
}

void GameController::mainMenu() {
	bool inPlay = true;
	while (inPlay) {
		printMenu();
		switch (tolower(move[0])) {
			case '1':
				adventure->select();
				break;
			case '2':
				highScore->hof();
				break;
			case '3':
				cout << "valid move" << endl;
				break;
			case '4':
				about->printAbout();
				break;
			case '5':
				cout << "Are you sure you want to quit?" << endl;
				char temp;
				cin >> temp;
				if (tolower(temp) == 'y') {
					inPlay = false;
				}
				temp = NULL;
				
			default:
				if (move == "1" || move == "2" || move == "3" || move == "4" || move == "5") {
					
				}
				else {
					cout << "invalid move" << endl;
				}
				break;
		}
	}
}
void GameController::printMenu() {
	cout << "Zorkish :: MainMenu" <<endl;
	cout << "----------------------------------------------" << endl;
	cout << " " << endl;
	cout << "1. Select Adventure and Play" << endl;
	cout << "2. Hall of Fame" << endl;
	cout << "3. Help" << endl;
	cout << "4. About" << endl;
	cout << "5. Quit" << endl;
	cout << "Select 1-5" << endl;
	cin >> move;
}
