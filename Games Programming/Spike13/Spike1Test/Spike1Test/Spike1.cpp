#include "Spike1.h"




string checkmove() {
	string moves = "";
	bool checkfirstmove = false;
	if (_map[PlayerPosY - 1][PlayerPosX] != "#" && PlayerPosY > 0) {
		moves =  "N";
		checkfirstmove = true;
	}
	
	if (_map[PlayerPosY + 1][PlayerPosX] != "#" && PlayerPosY < 7) {
		if (checkfirstmove) {
			moves += ", ";
		}
		moves += "S";
		checkfirstmove = true;
	}
	if (_map[PlayerPosY][PlayerPosX - 1] != "#" && PlayerPosX > 0) {
		if (checkfirstmove) {
			moves += ", ";
		}
		moves += "W";
		checkfirstmove = true;
	}
	if (_map[PlayerPosY][PlayerPosX + 1] != "#" && PlayerPosX < 7) {
		if (checkfirstmove) {
			moves += ", ";
		}
		moves += "E";
		checkfirstmove = true;
	}
	return moves;
}

string input() {

	bool correctmove = false;
	while (correctmove == false) {
		cout << "Select Move  from " << checkmove() << endl;
		cin >> playermove;
		switch (tolower(playermove[0])) {
		case 'n':case 's':case 'e':case 'w': case 'q':
			correctmove = true;
			break;
		default:
				cout << "invalid move" << endl;
				return "invalid move";
		}
	}

	return "correct";
}

void update() {
	if (playermove == "w") {
		if (_map[PlayerPosY][PlayerPosX - 1] != "#" && PlayerPosX >= 0) {
			PlayerPosX--;
		}
	}
	else if (playermove == "e") {
		if (_map[PlayerPosY][PlayerPosX + 1] != "#" && PlayerPosX <= 7) {
			PlayerPosX++;
		}
	}
	else if (playermove == "n") {
		if (_map[PlayerPosY - 1][PlayerPosX] != "#" && PlayerPosY >= 0) {
			PlayerPosY--;
		}
	}
	else if (playermove == "s") {
		if (_map[PlayerPosY + 1][PlayerPosX] != "#" && PlayerPosY <= 7) {
			PlayerPosY++;
		}
	}
	else if (playermove == "q") {
		cout << "Why you quit this awesome GAME?" << endl;
		cout << "The Game has ended. Enter any key to exit";
		cin >> playermove;
		return exit(0);
	}
}


void render() {
	cout << endl;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == PlayerPosY && j == PlayerPosX) {
				cout << "P";
			}
			else {
				cout << _map[i][j];
			}

		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cout << "Welcome to GridWorld!" << endl;
	cout << "Valid Commands: N,S,E and W for Directions and Q to quit" << endl;
	while (GameState) {
		input();
		update();
		render();
		if (_map[PlayerPosY][PlayerPosX] == "G") {
			cout << "Congrates you won the GAME!" << endl;
			cout << "The Game has ended. Enter any key to exit";
			cin >> playermove;
			exit(0);
		}
		if (_map[PlayerPosY][PlayerPosX] == "D") {
			cout << "Sorry you lost the GAME!:(" << endl;
			cout << "The Game has ended. Enter any key to exit";
			cin >> playermove;
			exit(0);
		}
	}
    return 0;
}

