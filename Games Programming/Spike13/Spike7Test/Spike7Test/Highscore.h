#pragma once
#include "Header.h"
class HighScore
{
public:
	HighScore();
	~HighScore();
	void newHighScore(int score, string world);
	void printNewHighScore();
	void hof();
private:
	string move;
};
