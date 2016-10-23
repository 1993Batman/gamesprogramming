#include "stdafx.h"
#include "Gameplay.h"

Gameplay::Gameplay()
{
	move = "";
	locations = vector<Location*>();
	worldSetUp();
	cm = new CommandManager();
}

Gameplay::~Gameplay()
{
	delete(&locations);
	delete(currLoc);
	delete(cm);
}

void Gameplay::play() {
	bool inPlay = true;
	cin.ignore();
	currLoc = locations.at(0);
	cout << "Zorkish :: Gameplay" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " " << endl;
	cout << "This is simple and pointless. This is only for testing... But Lets Play Anyway" << endl;
	while (inPlay) {
		printGameplay();

		if (move == "false") {
			inPlay = false;
		}
		else if (move == "north" || move == "south" || move == "east" || move == "west" || 
			move == "northwest" || move == "northeast" ||
			move == "southwest" || move == "southeast") {
			vector<Edges*> posMove = currLoc->getEdges();
			for (int i = 0; i < int(posMove.size()); i++) {
				for (int j = 0; j < int(locations.size()); j++) {
					if (move == posMove.at(i)->getPath()) {
						if (posMove.at(i)->getNode() == locations.at(j)->getName()) {
							currLoc = locations.at(j);
							cout << posMove.at(i)->getDesc() << endl;
							break;
						}
					}
				}
			}
		} else if( move == " "){}
		else {
			cout << move;
		}
		
	}
}

void Gameplay::printGameplay() {
	
	cout << currLoc->getDec() << endl;
	cout << "You can travel:" << endl;
	string movement = "";
	vector<Edges*> posMove = currLoc->getEdges();
	for (int i = 0; i < int(posMove.size()); i++) {
		movement += posMove.at(i)->getPath() + ",";
	}
	cout << movement << endl;
	getline(cin, move);
	transform(move.begin(), move.end(), move.begin(), ::tolower);
	move = cm->checkCommand(move, currLoc);
}



void Gameplay::worldSetUp() {
	string line, location,desc,edge;
	vector<Edges*> ve;
	ve = vector<Edges*>();
	vector<string> token;
	Inventory* i = new Inventory("Null", "Null", "Null");
	Weapon* w = new Weapon("Null", "Null", "Null", 0);
	Entity* e = new Entity("Null", "Null", 0);
	ifstream input("World.txt");
	while (getline(input, line)) {
		
		Utilities::Split(line,':', token);
		if (token[0] == "Location") {
			location = token[1];
		}
		else if (token[0] == "Desc") {
			desc = token[1];
		}
		else if (token[0] == "Edge") {
			Edges* e = new Edges(token[1], token[2], token[3], token[4]);
			ve.push_back(e);
		}

		if(token[0] == "Entity")
		{
			e = new Entity(token[1], token[2], stoi(token[3]));
		}
		 if (token[0] == "Weapon")
		{
			w = new Weapon(token[1], token[2], token[3], stoi(token[4]));

		 }
		 if (token[0] == "Inventory")
		{
			i = new Inventory(token[1], token[2], token[3]);

		 }

		if (token[0] == "End") {
			locations.push_back(new Location(location, desc, ve, *e, *i, *w));
			ve.clear();
			i = new Inventory("Null", "Null", "Null");
			w = new Weapon("Null", "Null", "Null", 0);
			e = new Entity("Null", "Null", 0);
		}

		token.clear();
	}
	input.close();

	cout << "Great Success! The Game Loaded" << endl;
}