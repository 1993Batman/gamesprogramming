#include "stdafx.h"
#include "CommandManager.h"

CommandManager::CommandManager() {
	lc = new LookCommand();
	mc = new MoveCommand();
	hscore = new HighScore();
}

CommandManager::~CommandManager() {
	delete(lc);
	delete(mc);
}

string CommandManager::checkCommand(string m, Location* l) {
	vector<Edges*> e = vector<Edges*>(l->getEdges());
	

	bool checkL = lc->checkCommand(m, l);
	if (checkL) {
		return " ";
	}


	if (m == "rkooutofnowhere") {
		cout << "You here a rattle... you are scared and don't know what to do" << endl;
		cout << "You start to get worried and then" << endl;
		cout << "What do you do?" << endl;
		cin >> m;
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
		cout << "You have now lost and connot play the game anymore" << endl;
		cout << "Select any key to continue" << endl;
		cin >> m;
		exit(0);
	}
	string check = mc->checkCommand(m);

	if (check != "No") {
		for (int i = 0; i < int(e.size()); i++) {
			if (e.at(i)->getPath() == check) {
				return check;
			}
		}
	}

	if (m == "quit") {
		cout << "Your adventure has ended... You lost The Game!" << endl;
		return "false";
		
	}
	else if (m == "highscore") {
		hscore->newHighScore(50, "Void World");
		return "false";
	}

	return "I'm sorry you forgot how to Zorkish: \n";
};