#include "stdafx.h"
#include "GameController.h"

GameController::GameController() {
	move = " ";
	player = new Player();
}

GameController::~GameController()
{

	delete(player);
}

void GameController::mainMenu() {
	bool inPlay = true;
	while (inPlay) {
		printMenu();
		switch (tolower(move[0])) {
			case '1':
				testInventory();
				break;
			case '2':
				cout << "Are you sure you want to quit?" << endl;
				char temp;
				cin >> temp;
				if (tolower(temp) == 'y') {
					inPlay = false;
				}
				temp = NULL;
				
			default:
				if (move == "1" || move == "2" ) {
					
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
	cout << "1. Test Inventory" << endl;
	cout << "2. Quit" << endl;
	cout << "Select 1-2" << endl;
	cin >> move;
}


void GameController::testInventory() {
	Inventory* item1 = new Inventory("Sword Of Truth", "Weapon", "Mighty fine Sword that doesn't lie");
	Inventory* item2 = new Inventory("Keys of the Kingdom", "Keys", "Tossed the Keys of the Kingdom in my backpack");
	Inventory* item3 = new Inventory("Hand of God", "Misc", "This is the same hand Maradona used to win the 1986 World Cup");
	Inventory* item4 = new Inventory("Banana", "Food", "Banana?");
	Inventory* item5 = new Inventory("Beer Potion", "Potion", "Stimulates your senses to the average drunk");
	
	player->AddItem(*item1);
	player->AddItem(*item2);
	player->AddItem(*item3);
	player->AddItem(*item4);
	player->AddItem(*item5);
	
	cout << "I just added these to the inventory"<< endl;
	player->ShowItems;

	
}