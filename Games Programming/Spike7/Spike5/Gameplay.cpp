#include "stdafx.h"
#include "Gameplay.h"

Gameplay::Gameplay()
{
	move = " ";
	hscore = new HighScore();
	locations = new vector<Location>();
	setUpLocations();
	currLoc = &locations->at(0);
}

Gameplay::~Gameplay()
{
	delete(hscore);
	delete(locations);
	delete(currLoc);
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
	cout << "This is simple and pointless. This is only for testing... But Lets Play Anyway" << endl;
	cout << currLoc->getDec() << endl;
	cout << "You can travel:"<< endl;
	string movement = "";
	for (int i = 0; i < currLoc->getSize(); i++) {
		//movement += 
	}

	cin >> move;
	transform(move.begin(), move.end(), move.begin(), ::tolower);
}

void Gameplay::setUpLocations() {
	vector<Edges>* ve1;
	vector<Edges>* ve2;
	vector<Edges>* ve3;
	vector<Edges>* ve4;
	vector<Edges>* ve5;
	ve1 = new vector<Edges>();
	ve2 = new vector<Edges>();
	ve3 = new vector<Edges>();
	ve4 = new vector<Edges>();
	ve5 = new vector<Edges>();
	
	ve1->insert(ve1->begin(), *new Edges("Edge1", "Node2", "north", "You travel north and realise youy forgot your lunch"));

	ve2->insert(ve2->begin(), *new Edges("Edge2", "Node5", "west", "You grow hungery and see a ham sandwich"));
	ve2->insert(ve2->begin()+1, *new Edges("Edge2", "Node3", "northeast", "As you walk you see chicken nuggets"));
	ve2->insert(ve2->begin()+2, *new Edges("Edge2", "Node1", "south", "You have to go back to get your lunch"));

	ve3->insert(ve3->begin(), *new Edges("Edge3", "Node2", "southwest", "It was a lie! There were no chicken nuggets! You go back"));
	ve3->insert(ve3->begin()+1, *new Edges("Edge3", "Node4", "southeast", "The chicken nuggets moved this way"));

	ve4->insert(ve4->begin(), *new Edges("Edge4", "Node3", "southwest", "It was a lie! There were no chicken nuggets! You go back"));

	ve5->insert(ve5->begin(), *new Edges("Edge5", "Node2", "east", "It was a lie! There were no chicken nuggets! You go back"));

	Location* l1 = new Location("Node1","Testing go straight please",*ve1,true);
	Location* l2 = new Location("Node2", "You reach a crossroad and try to see where the delicous food is comming from", *ve2, false);
	Location* l3 = new Location("Node3", "You follow your sense of smell but you're not sure where the food is", *ve3,false);
	Location* l4 = new Location("Node4", "It was a lie and you fell bad and you should fell bad", *ve4, false);
	Location* l5 = new Location("Node5", "Eww you realise the ham sandwich is off and decide to follow a different path", *ve5, false);

	locations->insert(locations->begin(), *l1);
	locations->insert(locations->begin()+1, *l2);
	locations->insert(locations->begin()+2, *l3);
	locations->insert(locations->begin()+3, *l4);
	locations->insert(locations->begin()+4, *l5);
}