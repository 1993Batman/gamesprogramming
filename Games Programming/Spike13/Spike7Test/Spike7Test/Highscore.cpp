
#include "HighScore.h"

HighScore::HighScore()
{
	move = " ";
}

HighScore::~HighScore()
{
}

void HighScore::newHighScore(int score, string world)
{
	printNewHighScore();
	cout << "" << endl;
	cout << "Adventure: " << world << endl;
	cout << "Score: " << score << endl;
	cout << "Moves: " << "Over 8000" << endl;
	cout << "" << endl;
	cout << "Enter your name to for Zorkish Immortality" << endl;
	cin >> move;
}

void HighScore::printNewHighScore()
{
	cout << "Zorkish :: New High Score" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << " " << endl;
	cout << "You're sitting in the Hall of Fame" << endl;
	cout << "Where everyone (playing this game) is going to know you're name" << endl;

}

void HighScore::hof()
{
	cout << "Zorkish :: Hall of Fame" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << " " << endl;
	cout << "These are the people sitting in the Hall of Fame" << endl;
	cout << "" << endl;
	cout << "1. Goku, Planet Namek, 8001" << endl;
	cout << "2. Fred, Mountain World, 5000" << endl;
	cout << "3. Mary, Mountain World, 4000" << endl;
	cout << "4. Joe, Water World, 3000" << endl;
	cout << "5. Henry, Mountain World, 2000" << endl;
	cout << "6. Susan, Mountain World, 1000" << endl;
	cout << "7. Alfred, Water World, 900" << endl;
	cout << "8. Clark, Mountain World, 800" << endl;
	cout << "9. Harold, Mountain World, 500" << endl;
	cout << "10. Julie, Water World, 300" << endl;
	cout << "" << endl;
	cout << "Press any key to return to the Main Menu" << endl;

}