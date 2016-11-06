#include "stdafx.h"
#include "Gameplay.h"

Gameplay::Gameplay()
{
	move = "";
	locations = vector<Location*>();
	worldSetUp();
	cm = new CommandManager();
	player = new Player();
	bb = new MessageHandler();
}

Gameplay::~Gameplay()
{
	delete(&locations);
	delete(cm);
	delete(player);
	delete(bb);
}

void Gameplay::play() {
	bool inPlay = true;
	cin.ignore();
	currLoc = 0;
	cout << "Zorkish :: Gameplay" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " " << endl;
	cout << "This is simple and pointless. This is only for testing... But Lets Play Anyway" << endl;
	while (inPlay) {
		printGameplay();
		vector<string> ss;
		Utilities::Split(move, ' ', ss);
		if (move == "false") {
			inPlay = false;
		}else if(bb->MessagesExist()){
			Message* temp;
			temp = bb->CheckMessage(locations.at(currLoc)->getName());
			vector<string> ss2;
			Utilities::Split(locations.at(currLoc)->getMessage(bb->CheckMessage(locations.at(currLoc)->getName())), ' ', ss2);
			
			if (ss2[0] == "move") {
				vector<string> ss3;
				Utilities::Split(ss2[1], '-', ss3);
				currLoc = atoi(ss3[1].c_str()) - 1;
				bb->ClearMessage(temp);
				if (locations.at(currLoc)->getMessRes() == true) {
					player->returnHC().Damage(locations.at(currLoc)->returnDC().Attack());
					cout << "You trip on some spikes and hurt yourself. You're now at " << player->returnHC().GetHealth() << endl;
				}
			}
			if (ss2[0] == "node" && ss[1] == "all") {
				for (int i = 0; i < int(locations.size()); i++) {
					if (locations.at(i)->getMessRes() == false) {
						locations.at(i)->setMessRes(true);
						cout << locations.at(i)->returnDC().GetDamage() << endl;
					}
				}
				cout << "You hear a noise and proceed with caution" << endl;
			}
			
			bb->ClearMessage(temp);
			if (ss[0] == "attack") {

			}
		} else if( move == " "){}
		else if (move == "open bag") {
			if (player->getBag()->openCloseBagCheck() == true) {
				player->getBag()->openCloseBag();
				cout << "Bag is now open" << endl;
			}
			else {
				cout << "Bag is already open" << endl;
			}
		}
		else if (move == "close bag") {
			if (player->getBag()->openCloseBagCheck() == false) {
				player->getBag()->openCloseBag();
				cout << "Bag is now closed" << endl;
			}
			else {
				cout << "Bag is already closed" << endl;
			}
		}
		else if(move == "add item"){
			if (player->getBag()->openCloseBagCheck() == false) {
				player->AddItem(locations.at(currLoc)->getItem());
				locations.at(currLoc)->setItem(new Item("Null", "Null", "Null"));
				cout << "You have succesfully picked up the item" << endl;
			}
			else {
				cout << "Your bag is closed" << endl;
			}
		}
		else if (ss[0] == "remove") {
			for (int i = 0; i < int(player->getBag()->bag.size()); i++) {
				if (!player->getBag()->bag.at(i).ReturnName().compare(ss[1])) {
					player->RemoveItem(player->getBag()->bag.at(i));
					cout << "You have succesfully removed the item forever! you can't get it back..." << endl;
					cout << "I'm sorry but it's the unwritten rule of Zorkish" << endl;
				}
			}
		}
		else if (move == "look in bag") {
			player->getBag()->printItemsInBag();
		}
		else if (move == "attack entity") {
			if (int(player->getBag()->bag.size()) == 0) {
				cout << "How do you expect to attack someone without a weapon" << endl;
			}
			else if (&player->getBag()->bag.at(0).returnDC() == nullptr) {
				cout << "You item doesnt have any damage conponent attached to it" << endl;
			}
			locations.at(currLoc)->getEntity().beenAttacked(player->getBag()->bag.at(0).returnDC().Attack());
			locations.at(currLoc)->getEntity().printInfo();
		}
		else {
			cout << move;
		}
		

	}
}

void Gameplay::printGameplay() {

	cout << locations.at(currLoc)->getDec() << endl;
	cout << "You can travel:" << endl;
	string movement = "";
	vector<Edges*> posMove = locations.at(currLoc)->getEdges();
	for (int i = 0; i < int(posMove.size()); i++) {
		movement += posMove.at(i)->getPath() + ",";
	}
	cout << movement << endl;
	getline(cin, move);
	transform(move.begin(), move.end(), move.begin(), ::tolower);
	move = cm->checkCommand(move, locations.at(currLoc), player->getBag()->bag);
	vector<string> ss;
	Utilities::Split(move, ' ', ss);
	if (ss[0] == "move") {
		bb->CreateMessage(new Message(ss[1], ss[0], locations.at(currLoc)->getName()));
	}
	if (move == "have a nice fall") {
		bb->CreateMessage(new Message("node all", "have a nice fall", locations.at(currLoc)->getName()));
	}
	

}



void Gameplay::worldSetUp() {
	string line, location,desc,edge;
	vector<Edges*> ve;
	ve = vector<Edges*>();
	vector<string> token;
	Item* i = new Item("Null", "Null", "Null");
	Entity* e = new Entity("Null", "Null");
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
			e = new Entity(token[1], token[2]);
		}
		 if (token[0] == "Item")
		{
			i = new Item(token[1], token[2], token[3]);
			if (int(token.size()) == 5) {
				i->GetDamage(2);
			}
		 }

		if (token[0] == "End") {
			locations.insert( locations.begin(),new Location(location, desc, ve, *e, *i));
			ve.clear();
			i = new Item("Null", "Null", "Null");
			e = new Entity("Null", "Null");
			locations.at(0)->GetDamage(1);
		}

		token.clear();
	}
	input.close();

	cout << "Great Success! The Game Loaded" << endl;
}
