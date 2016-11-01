#include "stdafx.h"
#include "CommandManager.h"

CommandManager::CommandManager() {
	lc = new LookCommand();
	mc = new MoveCommand();
	hscore = new HighScore();
	occ = new OpenCloseCommand();
	ic = new ItemCommand();
}

CommandManager::~CommandManager() {
	delete(lc);
	delete(mc);
	delete(occ);
	delete(ic);
}

string CommandManager::checkCommand(string m, Location* l, vector<Item> ve) {
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
	if (m == "highscore") {
		hscore->newHighScore(50, "Void World");
		return "false";
	}

	check = occ->checkCommand(m);

	if (check == "open bag" || check == "close bag") {
		return check;
	}

	check = ic->checkCommand(m,ve,l->getItem());
	if (check == "add item" || check == "look in bag" || check == " ") {
		return check;
	}
	vector<string> ss;
	Utilities::Split(check, ' ', ss);
	if (ss[0] == "remove" && int(ss.size()) > 1) {
		return "remove " + ss[1];
	}

	return "I'm sorry you forgot how to Zorkish: \n";
};