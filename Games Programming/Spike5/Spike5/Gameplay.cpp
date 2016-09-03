#include "stdafx.h"
#include "Gameplay.h"

Gameplay::Gameplay()
{
	move = " ";
	hscore = new HighScore();
}

Gameplay::~Gameplay()
{
	delete(hscore);
}

void Gameplay::play() {
	bool inPlay = true;
	while (inPlay) {
		printGameplay();
		if (move == "quit") {
			cout << "Your adventure has ended... You lost The Game!" << endl;
			inPlay = false;
		}
		else if (move == "highscore") {
			hscore->newHighScore(50, "Void World");
			inPlay = false;
		}
		else {
			cout << "invalid move" << endl;
		}
		
	}
}

void Gameplay::printGameplay() {
	cout << "Zorkish :: Gameplay" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " " << endl;
	cout << "This is simple and pointless. This is only for testing..." << endl;
	cin >> move;
	transform(move.begin(), move.end(), move.begin(), ::tolower);
}