
#include "Gameplay.h"

Gameplay::Gameplay()
{
	move = " ";
	hscore = new HighScore();
	locations = vector<Location*>();
	//setUpLocations();
	worldSetUp();

}

Gameplay::~Gameplay()
{
	delete(hscore);
	delete(&locations);
	delete(currLoc);
}

void Gameplay::play() {
	bool inPlay = true;
	currLoc = locations.at(0);
	cout << "Zorkish :: Gameplay" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " " << endl;
	cout << "This is simple and pointless. This is only for testing... But Lets Play Anyway" << endl;
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
		}
		else if (move == "rkooutofnowhere") {
			cout << "You here a rattle... you are scared and don't know what to do" << endl;
			cout << "You start to get worried and then" << endl;
			cout << "What do you do?" << endl;
			cin >> move;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << "Randy Orton comes out of nowhere and you recive a RKO OUT OF NOWHERE and die" << endl;
			cout << "You have now lost" << endl;
			cout << "Select any key to continue" << endl;
			cin >> move;
			inPlay = false;
		}
		else if (move == "look") {
			vector<Edges*> posMove = currLoc->getEdges();
			cout << "You're not sure on how to Zorkish so you look at you're trusty map and see:";
			cout << currLoc->getName() << ":" << currLoc->getDec() << endl;
			cout << "Path:";
			for (int i = 0; i < int(posMove.size()); i++) {
				cout << posMove.at(i)->getPath() << ",";
				cout << " " << endl;
			}
		}
		else {
			cout << "invalid move" << endl;
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
	cin >> move;
	transform(move.begin(), move.end(), move.begin(), ::tolower);
	for (int j = 0; j < int(posMove.size()); j++) {
		if (move == posMove.at(j)->getPath()) {
			break;
		}
	}
}

void Gameplay::setUpLocations() {
	vector<Edges*> ve1;
	vector<Edges*> ve2;
	vector<Edges*> ve3;
	vector<Edges*> ve4;
	vector<Edges*> ve5;
	ve1 = vector<Edges*>();
	ve2 = vector<Edges*>();
	ve3 = vector<Edges*>();
	ve4 = vector<Edges*>();
	ve5 = vector<Edges*>();

	ve1.insert(ve1.begin(), new Edges("Edge1", "Node2", "north", "You travel north and realise youy forgot your lunch"));

	ve2.insert(ve2.begin(), new Edges("Edge2", "Node5", "west", "You grow hungery and see a ham sandwich"));
	ve2.insert(ve2.begin() + 1, new Edges("Edge2", "Node3", "northeast", "As you walk you see chicken nuggets"));
	ve2.insert(ve2.begin() + 2, new Edges("Edge2", "Node1", "south", "You have to go back to get your lunch"));

	ve3.insert(ve3.begin(), new Edges("Edge3", "Node2", "southwest", "It was a lie! There were no chicken nuggets! You need to go back"));
	ve3.insert(ve3.begin() + 1, new Edges("Edge3", "Node4", "southeast", "The chicken nuggets moved this way"));

	ve4.insert(ve4.begin(), new Edges("Edge4", "Node3", "southwest", "It was a lie! There were no chicken nuggets! You need to go back"));

	ve5.insert(ve5.begin(), new Edges("Edge5", "Node2", "east", "You travel back and try another path in search for food"));

	Location* l1 = new Location("Node1", "Testing go straight please", ve1);
	Location* l2 = new Location("Node2", "You reach a crossroad and try to see where the delicous food is comming from", ve2);
	Location* l3 = new Location("Node3", "You follow your sense of smell but you're not sure where the food is", ve3);
	Location* l4 = new Location("Node4", "It was a lie and you feel bad and you should feel bad", ve4);
	Location* l5 = new Location("Node5", "Eww you realise the ham sandwich is off and decide to follow a different path", ve5);


	locations.push_back(l1);
	locations.push_back(l2);
	locations.push_back(l3);
	locations.push_back(l4);
	locations.push_back(l5);
}

void Gameplay::worldSetUp() {
	string line, location, desc, edge;
	vector<Edges*> ve;
	ve = vector<Edges*>();
	vector<string> token;
	ifstream input("World.txt");
	while (getline(input, line)) {

		Utilities::Split(line, ':', token);
		if (token.empty() || token[0] == "End") {
			locations.push_back(new Location(location, desc, ve));
			ve.clear();
		}
		else if (token[0] == "Location") {
			location = token[1];
		}
		else if (token[0] == "Desc") {
			desc = token[1];
		}
		else if (token[0] == "Edge") {
			Edges* e = new Edges(token[1], token[2], token[3], token[4]);
			ve.push_back(e);
		}
		token.clear();
	}
	input.close();

	cout << "Great Success! The Game Loaded" << endl;
}